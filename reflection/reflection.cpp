// reflection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>

#include "boost/fusion/functional.hpp"
#include "boost/fusion/tuple.hpp"
#include "boost/fusion/include/at_c.hpp"
#include "boost/fusion/adapted/struct/adapt_struct.hpp"
#include <boost/fusion/include/adapt_struct_named.hpp>
#include "boost/fusion/adapted.hpp"

template<class T> 
void print_xml(const T& t) 
{ 
  for_each(t, [](const auto& x) {
    std::cout << '<' << typeid(x).name() << '>' << 
      x << 
      "</" << typeid(x).name() << '>' << std::endl;
  }); 
}

struct person {
  std::string name; int age;

  //std::make_tuple(std::make_tuple(name, "name"), std::make_tuple(age, "age"));
};

BOOST_FUSION_ADAPT_STRUCT(person, (std::string, name) (int, age))

int main()
{

  using namespace boost::fusion;
  auto stuff = make_tuple(1, 'x', "howdy");
  int i = at_c<0>(stuff);
  char ch = at_c<1>(stuff);
  std::string s = at_c<2>(stuff);

  person ps = { "Tom", 52 };
  std::cout << at_c<0>(ps) << std::endl; // Tom

  std::string name = 
    boost::fusion::extension::struct_member_name<person, 0>::call();
  std::cout << name << std::endl; // name
  //print_xml(ps);
  return 0;
}