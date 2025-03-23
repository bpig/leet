//
// Created by sky on 3/23/25.
//

#ifndef LEET_0002_H
#define LEET_0002_H

#include "util.h"

/**
 * Definition for singly-linked list.

 *
 *
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single digit.
 * Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

    ListNode(string s) {
        if (s.empty()) {
            throw runtime_error("input s empty");
        }
        val = s[0] - '0';
        if (s.size() == 1) {
            next = nullptr;
        } else {
            next = new ListNode(s.substr(1));
        }
    }

    void print(bool newline = true) {
        if (next) {
            next->print(false);
        }
        cout << val;
        if (newline) {
            cout << endl;
        }
    }
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        return nullptr;
    }
};

void test() {
    auto l1 = ListNode("243");
    auto l2 = ListNode("564");
    l1.print();
    l2.print();
}

#endif //LEET_0002_H
