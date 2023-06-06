#include <gtest/gtest.h>

#include "list.hpp"

TEST(List_Test, creating) {
    list_container<int> l;
    int size_list = l.size();
    ASSERT_TRUE(size_list == 0);
}


TEST(List_Test, push_back) {
    int pushing_number = 1;
    list_container<int> l;
    l.push_back(0);
    l.push_back(pushing_number);
    int checking_number = l[1];
    ASSERT_TRUE(checking_number == pushing_number);
}

TEST(List_Test, inserting_forward) {
    int inserting_number = 1;
    list_container<int> l;
    l.push_back(0);
    l.insert(0, inserting_number);
    int checking_number = l[0];
    ASSERT_TRUE(checking_number == inserting_number);
}

TEST(List_Test, inserting_middle) {
    int inserting_number = 12;
    list_container<int> l;
    l.push_back(0);
    l.push_back(5);
    l.insert(1, inserting_number);
    int checking_number = l[1];
    ASSERT_TRUE(checking_number == inserting_number);
}

TEST(List_Test, erasing_from_the_end) {
    list_container<int> l;
    l.push_back(0);
    l.push_back(5);
    l.push_back(3);
    int full_list = l.size();
    l.erase(2);
    int list_after_erase = l.size();
    ASSERT_TRUE(list_after_erase < full_list);
}

TEST(List_Test, searching_from_end) {
    int inserting_number = 12;
    list_container<int> l;
    l.push_back(0);
    l.push_back(5);
    l.insert(1, inserting_number);
    int checking_number = l[-2];
    ASSERT_TRUE(checking_number == inserting_number);
}

TEST(List_Test, changing_numerology_with_delete) {
    int first_item = 0;
    int second_item = 35;
    int third_item = 12;
    int forth_item = 10;
    int deleted_item = 99;
    list_container<int> l;
    l.push_back(first_item);
    l.push_back(second_item);
    l.push_back(deleted_item);
    l.push_back(third_item);
    l.push_back(forth_item);
    l.erase(2);
    ASSERT_TRUE(l[2] == third_item);
}

TEST(List_Test, changing_numerology_with_insert) {
    int first_item = 0;
    int second_item = 35;
    int forth_item = 10;
    int fifth_item = 12;
    int inserting_item = 99;
    list_container<int> l;
    l.push_back(first_item);
    l.push_back(second_item);
    l.push_back(forth_item);
    l.push_back(fifth_item);
    l.insert(2, inserting_item);
    ASSERT_TRUE(l[3] == forth_item);
}

TEST(List_Test, correct_push_backing) {
    int first_item = 0;
    int second_item = 35;
    int third_item = 12;
    int forth_item = 10;
    list_container<int> l;
    l.push_back(first_item);
    l.push_back(second_item);
    l.push_back(third_item);
    l.push_back(forth_item);
    ASSERT_TRUE(l[0] == first_item && l[1] == second_item && l[2] == third_item && l[3] == forth_item);
}

TEST(List_Test, correct_multiply_erasing) {
    int first_item = 0;
    int second_item = 35;
    int third_item = 12;
    int forth_item = 10;
    list_container<int> l;
    l.push_back(first_item);
    l.push_back(second_item);
    l.push_back(third_item);
    l.push_back(forth_item);
    l.erase(0);
    l.erase(1);
    ASSERT_TRUE(l[0] == second_item && l[1] == forth_item);
}