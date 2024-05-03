//  LinkedList.cpp
//      <TODO: Describe the data structure here >
//
//  Author: Ashley Montgomery
//  CU ID: asmo5494
//  GitHub Username: nwlax37
//  Hours to complete lab: 6
//

#include "LinkedList.h"

// constructor, initialize class variables and pointers here if need.
LinkedList::LinkedList() {
  top_ptr_ = nullptr;
}

// deconstructor,
LinkedList::~LinkedList() {}

node* LinkedList::init_node(int data) {
  node* ret(new node);
  ret->data = data;
  ret->next = nullptr;
  return ret;
}

string LinkedList::report() {
  //Contract: input will be integers
  //Contract: output will be string of all int inputs, in order, starting from top, separated by spaces
  //Test 1: empty list returns ""
  //Test 2: 3 node list with data values 1,7,&3 returns "1 7 3 "
  //algorithm: if top_ptr_ = nullptr, ret = ""
  //algorithm: else create cursor for traversal, append string of int to ret, change cursor to point at next node
  string ret;
  node* cursor = top_ptr_;
  if (cursor != nullptr) {
      while (cursor != nullptr) {
        ret.append(to_string(cursor->data));
        ret.append(" ");
        cursor = cursor->next;
      }
  }
  else 
    ret = "";
  return ret;
}

void LinkedList::append_data(int data) {
  //Contract: input will be int
  //Contract: no output
  //algorithm: create new node
  //algorithm: if top_ptr_ = nullptr, top_ptr_ = new_node->next
  //algorithm: else 

  node* cursor = top_ptr_;
  node* app_node(new node);
  app_node->data = data;
  app_node->next = nullptr;

  if(cursor->next != nullptr) {
    while(cursor->next != nullptr) {
      cursor = cursor->next;
    }
    cursor->next = app_node;
  } else {
    top_ptr_->next = app_node;
  }
} 


void LinkedList::append(node* new_node) {
  node* cursor = top_ptr_;
  
  if(cursor != nullptr) {
    while(cursor->next != nullptr) {
      cursor = cursor->next;
    }
    cursor->next = new_node;
  } else {
    top_ptr_ = new_node;
  }
} 

void LinkedList::insert_data(int offset, int data) {
  //Contract: input will be index and value of new node
  //Contract: no output
  //algorithm: create new_node
  //algorithm: if index =0, new_node->next = top_ptr_, then top_ptr points to new node
  //algorithm: if index valid, move cursor through to offset index, then point prev node to new node, and new node to cursor
  //algorithm: if index < 0 or > last node, do nothing
  
  node* cursor = top_ptr_;
  node* ins_node(new node);
  ins_node->data = data;
  ins_node->next = nullptr;

  if(offset < 0) return;
  if(offset == 0) {
      ins_node->next = top_ptr_;
      top_ptr_ = ins_node;
      return;
  }  
  else
    for (int index = 0; index < (offset-1); index++) {
      if (cursor->next == nullptr) return; //offset out of bounds
      else cursor = cursor->next;
      }
    ins_node->next = cursor->next;
    cursor->next = ins_node;
    return; 
}

void LinkedList::insert(int offset, node* new_node) {
  node* cursor = top_ptr_;

  if(offset < 0) return;
  if(offset == 0) {
      new_node->next = top_ptr_;
      top_ptr_ = new_node;
      return;
  }  
  else
    for (int index = 0; index < (offset-1); index++) {
      if (cursor->next == nullptr) return; //offset out of bounds
      else cursor = cursor->next;
      }
    new_node->next = cursor->next;
    cursor->next = new_node;
    return; 
}

void LinkedList::remove(int offset) {
  node* cursor = top_ptr_;
  node* previous (new node);

  if (offset < 0) return;
  if (offset == 0) {
    top_ptr_ = top_ptr_->next;
  }
  for (int index = 0; index < offset; index++) {
    if (cursor->next == nullptr) return; //offset out of bounds
    else 
      previous = cursor;
      cursor = cursor->next;
    }
  previous->next = cursor->next;
  free(cursor);
}

int LinkedList::size() {
  int ret = 0;
  node* cursor = top_ptr_;

  if (cursor == nullptr) return ret;
  while(cursor != nullptr) {
      ret++;
      cursor = cursor->next;
    }
  return ret;
}

bool LinkedList::contains(int data) {
  bool ret = false;
  node* cursor = top_ptr_;
  while(cursor != nullptr) {
      if (cursor->data == data) return true;
      cursor = cursor->next;
    }
  return ret;
}

// This function is implemented for you
// It returns the top pointer
node* LinkedList::get_top() { return top_ptr_; }

// This function is implemented for you
// It sets a given pointer as the top pointer
void LinkedList::set_top(node* top_ptr) { top_ptr_ = top_ptr; }
