/* 
 * hash.c -- implements a generic hash table as an indexed set of queues.
 *
 */
#include <stdint.h>

/* 
 * SuperFastHash() -- produces a number between 0 and the tablesize-1.
 * 
 * The following (rather complicated) code, has been taken from Paul
 * Hsieh's website under the terms of the BSD license. It's a hash
 * function used all over the place nowadays, including Google Sparse
 * Hash.
 */
#define get16bits(d) (*((const uint16_t *) (d)))

static uint32_t SuperFastHash (const char *data,int len,uint32_t tablesize) {
  uint32_t hash = len, tmp;
  int rem;
  
  if (len <= 0 || data == NULL)
		return 0;
  rem = len & 3;
  len >>= 2;
  /* Main loop */
  for (;len > 0; len--) {
    hash  += get16bits (data);
    tmp    = (get16bits (data+2) << 11) ^ hash;
    hash   = (hash << 16) ^ tmp;
    data  += 2*sizeof (uint16_t);
    hash  += hash >> 11;
  }
  /* Handle end cases */
  switch (rem) {
  case 3: hash += get16bits (data);
    hash ^= hash << 16;
    hash ^= data[sizeof (uint16_t)] << 18;
    hash += hash >> 11;
    break;
  case 2: hash += get16bits (data);
    hash ^= hash << 11;
    hash += hash >> 17;
    break;
  case 1: hash += *data;
    hash ^= hash << 10;
    hash += hash >> 1;
  }
  /* Force "avalanching" of final 127 bits */
  hash ^= hash << 3;
  hash += hash >> 5;
  hash ^= hash << 4;
  hash += hash >> 17;
  hash ^= hash << 25;
  hash += hash >> 6;
  return hash % tablesize;
}

typedef struct node {
 	struct node *next;
 	void *element;
} node_t;

typedef struct hashtable {
 	node_t table[];
} hashtable_s;

hashtable_t *hopen(uint32_t hsize){
  hashtable_s *htp;
  sizeof(htp->table) = hsize;
  int i;
  for(i = 0; i<sizeof((hashtable_s *)htp->table); i< i++){
    (hashtable_s *)htp->table[i] = NULL;
  }
  return ((hashtable_t *)htp);
  }

void hclose(hashtable_t *htp){
  int i;
  for(i = 0; i<sizeof((hashtable_s *)htp->table); i< i++){
    node_t *p = (hashtable_s *)htp->table[i];

    while (p != NULL) {        
        node_t *temp = p;
        p = p->next;
        
        free(temp);
    }
    free(p);
  }
  free(htp);
}

int32_t hput(hashtable_t *htp, void *ep, const char *key, int keylen){
  int32_t loc = SuperFastHash(key, keylen, sizeof((hashtable_s *)htp->table));
  node_t *p = (hashtable_s *)htp->table[loc];
  if(p = NULL){
    p->element = ep;
    return 0;
  }
  while (p->next != NULL) {        
    p = p->next;   
  }
  p->next = ep;
  return 0;
}

void happly(hashtable_t *htp, void (*fn)(void* ep)){
  int i;
  for(i = 0; i<sizeof((hashtable_s *)htp->table); i< i++){
    node_t *p = (hashtable_s *)htp->table[i];

    while (p != NULL) {        
      fn(p->element);
      p = p->next;
    }
  }
}

void *hsearch(hashtable_t *htp, bool (*searchfn)(void* elementp, const void* searchkeyp), const char *key, int32_t keylen){
  int32_t loc = SuperFastHash(key, keylen, sizeof((hashtable_s *)htp->table));
  node_t *p = (hashtable_s *)htp->table[loc];
  int i;
  for(i = 0; i<sizeof((hashtable_s *)htp->table); i< i++){
    node_t *p = (hashtable_s *)htp->table[i];

    while (p != NULL) {        
      if(searchfn(p->element, key) == true){
        return p->element;
      }
      p = p->next;
    }
  }
  return NULL;
}

