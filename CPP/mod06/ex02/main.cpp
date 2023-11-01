/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:16:41 by manwe             #+#    #+#             */
/*   Updated: 2023/10/13 20:30:11 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base 
{
    public:
        virtual ~Base() {}
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base* generate(void)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    if (std::rand() % 3 == 2)
        return (new A);
    else if (std::rand() % 3 == 1)
        return (new B);
    else
        return (new C);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a;
        return;
    }
    catch(const std::exception& e) {}
    try
    {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void)b;
        return;
    }
    catch(const std::exception& e) {}
    try
    {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)c;
        return;
    }
    catch(const std::exception& e) {}
    std::cout << "Unkown type" << std::endl;
}

int main()
{
    Base* a = generate();
    Base* b = generate();
    Base* c = generate();
    Base* d = generate();

    std::cout << " a* = ";
    identify(a);
    std::cout << " a& = ";
    identify(*a);
    std::cout << " b* = ";
    identify(b);
    std::cout << " b& = ";
    identify(*b);
    std::cout << " c* = ";
    identify(c);
    std::cout << " c& = ";
    identify(*c);
    std::cout << " d* = ";
    identify(d);
    std::cout << " d& = ";
    identify(*d);
    std::cout << std::endl;
   
}