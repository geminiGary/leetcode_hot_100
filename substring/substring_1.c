#include <stdio.h>

#include <stdlib.h>

struct Entry {
    long key;
    int value;
    struct Entry *next;
};

// simple chained hash map for prefix sums
#define BUCKETS 40007  // prime ~2x numsSize

static struct Entry *buckets[BUCKETS];

static unsigned hash_func(long x) {
    // mix and mod
    unsigned h = (unsigned)(x ^ (x >> 33));
    return h % BUCKETS;
}

static void map_put(long key, int delta) {
    unsigned idx = hash_func(key);
    struct Entry *e = buckets[idx];
    while (e) {
        if (e->key == key) {
            e->value += delta;
            return;
        }
        e = e->next;
    }
    e = malloc(sizeof(*e));
    if (!e) return;
    e->key = key;
    e->value = delta;
    e->next = buckets[idx];
    buckets[idx] = e;
}

static int map_get(long key) {
    unsigned idx = hash_func(key);
    struct Entry *e = buckets[idx];
    while (e) {
        if (e->key == key) return e->value;
        e = e->next;
    }
    return 0;
}

int subarraySum(int* nums, int numsSize, int k) {
    long sum = 0;
    int count = 0;
    // clear buckets
    for (int i = 0; i < BUCKETS; i++) buckets[i] = NULL;
    map_put(0, 1);
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        count += map_get(sum - k);
        map_put(sum, 1);
    }

    // free entries (optional)
    for (int i = 0; i < BUCKETS; i++) {
        struct Entry *e = buckets[i];
        while (e) {
            struct Entry *next = e->next;
            free(e);
            e = next;
        }
        buckets[i] = NULL;
    }
    return count;
}

int main()
{
    int nums[]={1,2,3};
    int k=3;
    int ans=subarraySum(nums,3,k);
    printf("%d",ans);
    return 0;
}
