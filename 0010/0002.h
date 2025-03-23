//
// Created by sky on 3/23/25.
//

#ifndef LEET_0002_H
#define LEET_0002_H

#include "util.h"

/**
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
    ListNode *create_listnode(string s) {
        auto ans = new ListNode();
        if (s.empty()) {
            throw runtime_error("input s empty");
        }
        ans->val = s[0] - '0';
        if (s.size() == 1) {
            ans->next = nullptr;
        } else {
            ans->next = create_listnode(s.substr(1));
        }
        return ans;
    }


    void add(ListNode *l1, ListNode *l2, int carry, string &ans) {
        if (!l1 && !l2) {
            if (carry != 0) {
                ans.push_back(carry + '0');
            }
        } else if (!l1 || !l2) {
            int val = (l1 ? l1 : l2)->val + carry;
            ans.push_back(val % 10 + '0');
            add(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr, val / 10, ans);
        } else {
            int val = l1->val + l2->val + carry;
            ans.push_back(val % 10 + '0');
            add(l1->next, l2->next, val / 10, ans);
        }
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        string ans;
        add(l1, l2, 0, ans);
        return create_listnode(ans);
    }
};

void test() {
    auto s = Solution();
    {
        auto l1 = s.create_listnode("241");
        auto l2 = s.create_listnode("56");
        auto ans = s.addTwoNumbers(l1, l2);
        cout << "expect 207\n";
        ans->print();
    }
    {
        auto l1 = s.create_listnode("2431");
        auto l2 = s.create_listnode("564");
        auto ans = s.addTwoNumbers(l1, l2);
        cout << "expect 1807\n";
        ans->print();
    }
    {
        auto l1 = s.create_listnode("9999999");
        auto l2 = s.create_listnode("9999");
        auto ans = s.addTwoNumbers(l1, l2);
        cout << "expect 10009998\n";
        ans->print();
    }
    {
        auto l1 = s.create_listnode("0");
        auto l2 = s.create_listnode("0");
        auto ans = s.addTwoNumbers(l1, l2);
        cout << "expect 0\n";
        ans->print();
    }
}

#endif //LEET_0002_H
