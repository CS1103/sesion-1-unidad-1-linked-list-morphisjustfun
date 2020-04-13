//
// Created by utec on 4/11/20.
//

#include "linked_list.h"
#include <iostream>

using namespace std;

utec::first::linked_list_t::linked_list_t(const utec::linked_list_t &other) : size_(other.size_),tail_(other.tail_),head_(other.head_) {

}

utec::linked_list_t &utec::first::linked_list_t::operator=(const utec::linked_list_t &other) {

    this -> size_ = other.size_;
    this -> tail_ = other.tail_;
    this -> head_ = other.head_;
    return *this;
}

utec::first::linked_list_t::linked_list_t(utec::linked_list_t &&other) noexcept {
}

utec::linked_list_t &utec::first::linked_list_t::operator=(utec::linked_list_t &&other) noexcept {

    // TO DO
    return *this;
}

utec::first::linked_list_t::~linked_list_t() {

}

void utec::first::linked_list_t::push_front(int value) {

    /*
    auto node = new node_t{value, head_}
    head_ = node;
    */
    head_ = new node_t{value, head_};
    if (tail_ == nullptr) tail_ = head_;
    size_++;

}

void utec::first::linked_list_t::push_back(int value) {
    if (size_==0){
        auto node = new node_t {value,nullptr};
        head_ = node;
        tail_ = node;
        size_++;
    }
    else{
        auto node = new node_t {value,nullptr};
        tail_->next_=node;
        tail_=node;
        size_++;
    }
}

void utec::first::linked_list_t::insert(size_t index, int value) {
    node_t* node = head_;
    index = index-1;
    while (index--){
        node = node->next_;
    }
    auto node2 = new node_t{value,node->next_};
    node -> next_ = node2;
    size_++;
}

void utec::first::linked_list_t::pop_front() {
    if(size_!=0){
        auto node2 = head_ -> next_;
        delete head_;
        head_ = node2;
        size_ --;
    }
}

void utec::first::linked_list_t::pop_back() {
    if (size_!=0){
        auto pr = size_ - 2;
        auto node = head_;
        while(pr--){
            node = node ->next_;
        }
        delete tail_;
        tail_ = node;
        size_ --;
    }
}

void utec::first::linked_list_t::erase(size_t index) {
    if (index > size_-1 || index<0){
        cout << "El index especificado no existe" << endl;
    }
    else{
        index -=1;
        auto node = head_;
        while(index--){
            node = node ->next_;
        }
        auto node2 = node ->next_;
        node -> next_ = node2->next_;
        delete node2;
        size_ --;
    }
}

int &utec::first::linked_list_t::item(size_t index) {
    auto actual = head_;
    while (index--)
        actual = actual->next_;
    return actual->value_;
}

const int &utec::first::linked_list_t::item(size_t index) const {
    auto actual = head_;
    while (index--)
        actual = actual->next_;
    return actual->value_;
}

size_t utec::first::linked_list_t::size() const {
    return size_;
}
