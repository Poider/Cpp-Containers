/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ptriterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:49:00 by mel-amma          #+#    #+#             */
/*   Updated: 2022/12/22 11:49:26 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



//make it bidirectional
#ifndef _my_map_ptriter
#define _my_map_ptriter
#include <memory>
#include <algorithm>
#include <iterator>
#include "iterator_traits.hpp"
template <class T, class Allocator>
class map_ptrtor;

namespace ft{
template <typename map_ptr>
    class MapIterator
{
    public :
        typedef map_ptr                                                 iterator_type;
        typedef typename iterator_traits<map_ptr>::value_type           value_type;
        typedef typename iterator_traits<map_ptr>::difference_type      difference_type;
        typedef typename std::size_t                                size_type;
        typedef typename iterator_traits<map_ptr>::iterator_category    iterator_category;
        typedef typename iterator_traits<map_ptr>::pointer                pointer;
        typedef const  pointer          const_pointer;
        typedef typename iterator_traits<map_ptr>::reference              reference;
        typedef const  reference          const_reference;
    private :
        pointer ptr;
        template <class T1, class Allocator1>
           friend class map_ptrtor;
        MapIterator(pointer ptr):ptr(ptr) 
        {};

        //>>>>>friends
        template <typename it>
            friend class MapIterator;
        template <typename rit>
            friend class reverse_iterator;
        // template <typename ss>
        //     friend class MapIterator;
    public :
        pointer base() const
        {
            return ptr;
        };
        //default constructible only from forward iterator and ahead
        MapIterator(){};

        template <typename s>
        MapIterator(const MapIterator<s> &other) {
            this->ptr = other.base();
        };

        template <typename s>
        MapIterator<map_ptr>& operator=(const MapIterator<s> &other)
        {
            this->ptr = other.base();
            return *this;
        };
        ~MapIterator(){};

        //increments
            MapIterator<map_ptr>& operator++()//++x
            {
                ptr++;
                return *this;
            };
            MapIterator<map_ptr> operator++(int)//x++
            {
                MapIterator<map_ptr> temp = *this;
                ptr++;
                return temp;
            };
            MapIterator<map_ptr>& operator--()
            {
                ptr--;
                return *this;
            };
            MapIterator<map_ptr> operator--(int)
            {
                MapIterator<map_ptr> temp =*this;
                ptr--;
                return (temp);
            };

          
            MapIterator<map_ptr> operator+(int a) const
            {
                MapIterator<map_ptr>  temp;
                temp.ptr = ptr + a;
                return temp;
            };
            template <class iter>
            friend MapIterator<iter> operator+(int a, const MapIterator<iter>& map_ptrtor);
            MapIterator<map_ptr> operator-(int a)const
            {
                MapIterator<map_ptr>  temp;
                temp.ptr = ptr - a;
                return temp;
            };

            difference_type operator-(MapIterator<map_ptr> other)const
            {
                difference_type a;
                
                a = ptr - other.ptr;
                return a;
            };

           
            MapIterator& operator+=(int amount)
            {
                ptr = ptr + amount;
                return *this;
            };
            MapIterator& operator-=(int amount)
            {
                ptr = ptr - amount;
                return *this;
            };
            
            /*
            //operator * -> const op const for lvalue
            //operator * -> not const for rvalue
            */
            const_pointer operator->() const
            {
                return ptr;
            };
            const_reference operator*() const
            {
                return *ptr;
            };
            pointer operator->()
            {
                return ptr;
            };
            reference operator*()
            {
                return *ptr;
            };

            /**
             * @explanation
             * 
             [] is the ptr + number * hops
             op [] const op const // for read only in const objs
             op [] not const for writing
            */
            reference operator[](int index)
            {
                return *(ptr + index);
            };
            const_reference operator[](int index)const
            {
                return *(ptr + index);
            };

        // multipass?
             template <typename iterator1, typename iterator2>
            friend bool operator==(const MapIterator<iterator1> &it1, const MapIterator<iterator2> &it2);
            
            template <typename iterator1, typename iterator2>
            friend bool operator!=(const MapIterator<iterator1> &it1, const MapIterator<iterator2> &it2);

            template <typename iterator1, typename iterator2>
            friend bool operator>(const MapIterator<iterator1> &it1, const MapIterator<iterator2> &it2);

            template <typename iterator1, typename iterator2>
            friend bool operator>=(const MapIterator<iterator1> &it1, const MapIterator<iterator2> &it2);

            template <typename iterator1, typename iterator2>
            friend bool operator<(const MapIterator<iterator1> &it1, const MapIterator<iterator2> &it2);

            template <typename iterator1, typename iterator2>
            friend bool operator<=(const MapIterator<iterator1> &it1, const MapIterator<iterator2> &it2);
    };


template <typename iterator>
    class reverse_iterator
{
    public :
        typedef iterator                                                     iterator_type;
        typedef typename std::size_t                          size_type;
        typedef typename iterator_traits<iterator>::value_type                          value_type;
        typedef typename iterator_traits<iterator>::difference_type                     difference_type;
        typedef typename iterator_traits<iterator>::iterator_category    iterator_category;
        typedef typename iterator_traits<iterator>::pointer                pointer;
        typedef const typename iterator_traits<iterator>::pointer          const_pointer;
        typedef typename iterator_traits<iterator>::reference               reference;
        typedef const typename iterator_traits<iterator>::reference            const_reference;
    private :
        // pointer ptr;
        iterator_type it;
        template <class T1, class Allocator1>
           friend class map_ptrtor;
        reverse_iterator(pointer ptr) 
        {
            it = iterator_type(ptr);
        };


        //>>>>>friends 
        template <typename it>
            friend class MapIterator;
        template <typename rit>
            friend class reverse_iterator;
    public :
        iterator_type base() const
        {
            return it;
        };
        //default constructible only from forward iterator and ahead
        reverse_iterator(){};

        template <typename s>
            reverse_iterator(const reverse_iterator<s> &other) {
            it = other.base();
        };
        
        template <typename s>
            reverse_iterator<iterator>& operator=(const reverse_iterator<s> &other)
        {
            it =  other.base();
            return *this;
        };

        ~reverse_iterator(){};

        //increments
            reverse_iterator<iterator>& operator++()//++x
            {
                it--;
                return *this;
            };
            reverse_iterator<iterator> operator++(int)//x++
            {
                reverse_iterator<iterator> temp = *this;
                it--;
                return temp;
            };
            reverse_iterator<iterator>& operator--()
            {
                it++;
                return *this;
            };
            reverse_iterator<iterator> operator--(int)
            {
                reverse_iterator<iterator> temp = *this;
                it++;
                return temp;
            };

           
            reverse_iterator<iterator> operator+(int a)const
            {
                reverse_iterator<iterator>  temp;
                temp.it = it - a;
                return temp;
            };
            template <class iter>
            friend reverse_iterator<iter> operator+(int a, const reverse_iterator<iter>& map_ptrtor);
            reverse_iterator<iterator> operator-(int a)const
            {
                reverse_iterator<iterator>  temp;
                temp.it = it + a;
                return temp;
            };

            difference_type operator-(reverse_iterator<iterator> other)const
            {
                difference_type a;
                
                a = other.it - it;
                return a;
            };

           
            reverse_iterator& operator+=(int amount)
            {
                it = it - amount;
                return *this;
            };
            reverse_iterator& operator-=(int amount)
            {
                it = it + amount;
                return *this;
            };
            
            /*
            //operator * -> const op const for lvalue
            //operator * -> not const for rvalue
            */
            const_pointer operator->() const
            {
                iterator_type  temp = it;
                --temp;
                return temp.operator->();
            };
            const_reference operator*() const
            {
                iterator_type  temp = it;
                --temp;
                return temp.operator*();
            };
            pointer operator->()
            {
                iterator_type  temp = it;
                --temp;
                return temp.operator->();
            };
            reference operator*()
            {
                iterator_type  temp = it;
                --temp;
                return temp.operator*();
            };

            /**
             * @explanation
             * 
             [] is the ptr + number * hops
             op [] const op const // for read only in const objs
             op [] not const for writing
            */
            reference operator[](int index)
            {
                return *(it - index - 1);
            };
            const_reference operator[](int index)const
            {
                return *(it - index - 1);
            };

        // multipass?
            template <typename iterator1, typename iterator2>
            friend bool operator==(const reverse_iterator<iterator1> &it1, const reverse_iterator<iterator2> &it2);
            
            template <typename iterator1, typename iterator2>
            friend bool operator!=(const reverse_iterator<iterator1> &it1, const reverse_iterator<iterator2> &it2);

            template <typename iterator1, typename iterator2>
            friend bool operator>(const reverse_iterator<iterator1> &it1, const reverse_iterator<iterator2> &it2);

            template <typename iterator1, typename iterator2>
            friend bool operator>=(const reverse_iterator<iterator1> &it1, const reverse_iterator<iterator2> &it2);

            template <typename iterator1, typename iterator2>
            friend bool operator<(const reverse_iterator<iterator1> &it1, const reverse_iterator<iterator2> &it2);

            template <typename iterator1, typename iterator2>
            friend bool operator<=(const reverse_iterator<iterator1> &it1, const reverse_iterator<iterator2> &it2);
    };




template <class map_ptr>
MapIterator<map_ptr> operator+(int a, const MapIterator<map_ptr>& iter)
{
    MapIterator<map_ptr>  temp1;
    temp1 = iter.operator+(a);
    return (temp1);
};


template <class iterator>
reverse_iterator<iterator> operator+(int a, const reverse_iterator<iterator>& iter)
{
    reverse_iterator<iterator>  temp;
    temp = iter.operator+(a);
    return (temp);
};

//comparisons

template<typename iterator1,typename iterator2>
bool operator==(const reverse_iterator<iterator1> &it1,const reverse_iterator<iterator2> &it2)
{
    return (it1.it == it2.it);
};

template<typename iterator1,typename iterator2>
bool operator!=(const reverse_iterator<iterator1> &it1,const reverse_iterator<iterator2> &it2)
{
    return (it1.it != it2.it);
};

template<typename iterator1,typename iterator2>
bool operator>(const MapIterator<iterator1> &it1,const MapIterator<iterator2> &it2)
{
    return (it1.ptr > it2.ptr);
};

template<typename iterator1,typename iterator2>
bool operator>=(const MapIterator<iterator1> &it1,const MapIterator<iterator2> &it2)
{
    return (it1.ptr >= it2.ptr);
};

template<typename iterator1,typename iterator2>
bool operator<(const MapIterator<iterator1> &it1,const MapIterator<iterator2> &it2)
{
    return (it1.ptr < it2.ptr);
};

template<typename iterator1,typename iterator2>
bool operator<=(const MapIterator<iterator1> &it1,const MapIterator<iterator2> &it2)
{
    return (it1.ptr <= it2.ptr);
};

template<typename iterator1,typename iterator2>
bool operator>(const reverse_iterator<iterator1> &it1,const reverse_iterator<iterator2> &it2)
            {
                return (it1.it < it2.it);
                   
            };
template<typename iterator1,typename iterator2>         
bool operator>=(const reverse_iterator<iterator1> &it1,const reverse_iterator<iterator2> &it2)
{
    return (it1.it <= it2.it);
};

template<typename iterator1,typename iterator2>
bool operator<(const reverse_iterator<iterator1> &it1,const reverse_iterator<iterator2> &it2)
{
    return (it1.it > it2.it);
};

template<typename iterator1,typename iterator2>
bool operator<=(const reverse_iterator<iterator1> &it1,const reverse_iterator<iterator2> &it2)
{
    return (it1.it >= it2.it);
};

template<typename iterator1,typename iterator2>
bool operator==(const MapIterator<iterator1> &it1,const MapIterator<iterator2> &it2)
{
    return (it1.ptr == it2.ptr);
};

template<typename iterator1,typename iterator2>
bool operator!=(const MapIterator<iterator1> &it1,const MapIterator<iterator2> &it2)
{
    return (it1.ptr != it2.ptr);
};

}
#endif