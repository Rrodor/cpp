/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:34:10 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/28 15:22:49 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe & ref)
{
	(void)ref;
}

PmergeMe & PmergeMe::operator=(const PmergeMe & ref)
{
	(void)ref;
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::mergeList(std::list<int>::iterator begin, std::list<int>::iterator mid, std::list<int>::iterator end)
{
	std::list<int> left(begin, mid);
	std::list<int> right(mid, end);
	std::list<int>::iterator it = begin;
	std::list<int>::iterator it1 = left.begin();
	std::list<int>::iterator it2 = right.begin();
	while (it1 != left.end() && it2 != right.end())
	{
		if (*it1 <= *it2)
		{
			*it = *it1;
			it1++;
		}
		else
		{
			*it = *it2;
			it2++;
		}
		it++;
	}
	while (it1 != left.end())
	{
		*it = *it1;
		it1++;
		it++;
	}
	while (it2 != right.end())
	{
		*it = *it2;
		it2++;
		it++;
	}
}

void PmergeMe::mergeVec(std::vector<int>::iterator begin, std::vector<int>::iterator mid, std::vector<int>::iterator end)
{
	std::vector<int> left(begin, mid);
	std::vector<int> right(mid, end);
	std::vector<int>::iterator it = begin;
	std::vector<int>::iterator it1 = left.begin();
	std::vector<int>::iterator it2 = right.begin();
	while (it1 != left.end() && it2 != right.end())
	{
		if (*it1 <= *it2)
		{
			*it = *it1;
			it1++;
		}
		else
		{
			*it = *it2;
			it2++;
		}
		it++;
	}
	while (it1 != left.end())
	{
		*it = *it1;
		it1++;
		it++;
	}
	while (it2 != right.end())
	{
		*it = *it2;
		it2++;
		it++;
	}
}

void PmergeMe::mergeSortList(std::list<int> & list, std::list<int>::iterator begin, std::list<int>::iterator end)
{
	unsigned long int	i = 0;
	std::list<int> tmp(begin, end);
	if (tmp.size() < 2)
		return ;
	std::list<int>::iterator mid = begin;
	for (std::list<int>::iterator it = begin; it != end; it++)
		i++;
	i /= 2;
	while (i > 0)
	{
		mid++;
		i--;
	}
	mergeSortList(list, begin, mid);
	mergeSortList(list, mid, end);
	mergeList(begin, mid, end);
}

void PmergeMe::mergeSortVec(std::vector<int> & vec, std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	unsigned long int	i = 0;
	if (begin - end  + 1 >= 0)
		return ;
	std::vector<int>::iterator mid = begin;
	for (std::vector<int>::iterator it = begin; it != end; it++)
		i++;
	i /= 2;
	while (i > 0)
	{
		mid++;
		i--;
	}
	mergeSortVec(vec, begin, mid);
	mergeSortVec(vec, mid, end);
	mergeVec(begin, mid, end);
}

long long int	PmergeMe::getCurrentTimeMicros()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000LL) + tv.tv_usec;
}

void PmergeMe::mergeSort(std::vector<int> & vec, std::list<int> & list)
{
	long long int	stimevec;
	long long int	etimevec;
	long long int	stimelist;
	long long int	etimelist;
	std::cout << "Before : ";
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	stimevec = getCurrentTimeMicros();
	mergeSortVec(vec, vec.begin(), vec.end());
	etimevec = getCurrentTimeMicros();
	stimelist = getCurrentTimeMicros();
	mergeSortList(list, list.begin(), list.end());
	etimelist = getCurrentTimeMicros();
	std::cout << "After vec :  ";
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "After list :  ";
	for (std::list<int>::const_iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : ";
	std::cout << etimevec - stimevec << " us" << std::endl;
	std::cout << "Time to process a range of " << list.size() << " elements with std::list : ";
	std::cout << etimelist - stimelist << " us" << std::endl;
}
