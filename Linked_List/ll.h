#pragma once 

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

// #define ll_t void *
typedef void ll_t;
typedef void * ll_ptr_t;

// ll_t *create_head(int max_len, int head_data);
// int append(ll_t* ll, int data);
// void print_LL(ll_t *ll);
// void push(ll_t *ll, int data);
// int pop(ll_t *ll);
// int pull(ll_t *ll);
// void reverse_ll(ll_t *ll);


ll_ptr_t create_head(int max_len, int head_data);
int append(ll_ptr_t ll, int data);
void print_LL(ll_ptr_t ll);
void push(ll_ptr_t ll, int data);
int pop(ll_ptr_t ll);
int pull(ll_ptr_t ll);
void reverse_ll(ll_ptr_t ll);



