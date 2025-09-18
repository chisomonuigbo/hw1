#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

void ULListStr::push_back(const std::string& val) {
  if (tail_ == NULL) {
    tail_ = new Item();
    head_ = tail_;
  }

  if (tail_->last == ARRSIZE) {
    Item* temp = new Item();
    temp->val[0] = val;
    temp->first = 0;
    temp->last = 1;
    tail_->next = temp;
    temp->prev = tail_;
    tail_ = temp;
  }
  else {
    tail_->val[tail_->last ] = val;
    tail_->last = tail_->last + 1;
  }

  size_ = size_ + 1;
}

void ULListStr::pop_back() {
  if (tail_ == NULL) {
    return;
  }
  else {
    Item *temp = new Item();

    tail_->last = tail_->last - 1;
    size_ = size_ - 1;

    if (tail_->last == tail_->first) {
      tail_ = tail_->prev;
      if (tail_ != NULL) {
        tail_->next = NULL;
      }
      else {
        head_ = NULL;
      }
    }

  }
}

void ULListStr::push_front(const std::string& val){
  if (head_ == NULL) {
    head_ = new Item();
    head_->first = ARRSIZE;
    head_->last = ARRSIZE;
    tail_ = head_;
  }

  if (head_->first > 0) {
    head_->first = head_->first - 1;
    head_->val[head_->first] = val;
  }
  else {
    Item* temp = new Item();
    temp->first = ARRSIZE - 1;
    temp->last = ARRSIZE;
    temp->val[temp->first] = val;
    temp->next = head_;
    head_->prev = temp;
    head_ = temp;

  }
  size_ = size_ + 1;
}

void ULListStr::pop_front() {
  if (head_ == NULL) {
    return;
  }

  head_->first = head_->first + 1;
  size_ = size_ - 1;

  if (head_->first == head_->last) {
    head_ = head_->next;
      if (head_ != NULL) {
        head_->prev = NULL;
      }
      else {
        tail_ = NULL;
      }
  }
}

std::string const & ULListStr::back() const {
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const {
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc >= size_ )
  {
    return NULL;
  }

  Item* temp = head_;
  size_t iterate = 0;

  while (temp != nullptr && iterate < loc) {
    size_t numberOfItems = temp->last - temp->first;

    if (loc < iterate + numberOfItems) {
      return &temp->val[temp->first + (loc - iterate)];
    }
    iterate = iterate + numberOfItems;
    temp = temp->next;

  }

  return nullptr;
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
