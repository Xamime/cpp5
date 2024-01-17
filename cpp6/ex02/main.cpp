/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:41:26 by maxime            #+#    #+#             */
/*   Updated: 2023/12/19 15:45:07 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

class Base { public: virtual ~Base() {} };
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate(void)
{
    if ( std::rand() % 3 == 0 )
        return ( new A );
    else if ( std::rand() % 3 == 1 )
        return ( new B );
    else
        return ( new C );
}
/*
If the cast is successful, dynamic_cast returns a value of type target-type <A&*>.
If the cast fails and target-type is a pointer type, it returns a null pointer of that type.
If the cast fails and target-type is a reference type, it throws an exception that matches a handler of type std::bad_cast.
*/
void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "The actual pointer type is A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "The actual pointer type is B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "The actual pointer type is C\n";
}

void    identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "The actual reference type is A\n";
    }
    catch(const std::exception& e)
    {
        try
        {
            B& b= dynamic_cast<B&>(p);
            (void)b;
            std::cout << "The actual reference type is B\n";
        }
        catch(const std::exception& e)
        {
            try
            {
                C& c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "The actual reference type is C\n";
            }
            catch(const std::exception& e)
            {
            }
        }
    }
}

int main(){
    srand(time(NULL));
    Base* a = generate();
    Base* b = generate();
    Base* c = generate();
    
    identify(a);
    identify(*a);

    identify(b);
    identify(*b);

    identify(c);
    identify(*c);

    delete a;
    delete b;
    delete c;
    return 0;
}