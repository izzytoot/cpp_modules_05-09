/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:39:21 by icunha-t          #+#    #+#             */
/*   Updated: 2025/11/05 19:21:36 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& src): _deq(src._deq), _vec(src._vec), _debug(false) {}

PmergeMe& PmergeMe::operator= (const PmergeMe& src){
    if (this != &src){
        this->_deq = src._deq;
        this->_vec = src._vec;
    }
    return *this;
}

PmergeMe::~PmergeMe(){}

void PmergeMe::fillContainers(int ac, char** av){
    for (int i = 1; i < ac; i++){
        std::string currArg = av[i];
        std::string val;
        for (size_t j = 0; j < currArg.size(); j++){
            if (currArg[j] >= '0' && currArg[j] <= '9'){
                val += currArg[j];
            }
            else if (currArg[j] != ' ')
                throw std::runtime_error(RED "Error: invalid char in argument" RES);
        }
        int currNb;
        if (!val.empty()){
            currNb = std::atoi(val.c_str());
            if (currNb < 0 || currNb > 1000)
                throw std::runtime_error(RED "Error: invalid input value" RES);
            this->_vec.push_back(currNb);
            this->_deq.push_back(currNb);   
        }
        else
            throw std::runtime_error(RED "Error: empty argument" RES);
    }
}

void PmergeMe::sort(bool debug){  
    if (debug) 
        this->_debug = debug;
        
    std::cout << YEL << "Initial vector: " << RES;
    for (size_t j = 0; j < this->_vec.size(); j++)
        std::cout << this->_vec[j] << " ";
    std::cout << std::endl;

    try{
        clock_t start = clock();
        std::vector<std::vector<int> > sortedVec = pairAndSortVec();
        clock_t end = clock();
        
        std::cout << YEL << "Sorted vector: " << RES;
        for (int i = 0; i < static_cast<int>(sortedVec.size()); i++){
            for (int j = 0; j < static_cast<int>(sortedVec[i].size()); j++)
            std::cout << sortedVec[i][j] << " ";
        }  
        std::cout << std::endl;
        long _time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds
        std::cout << YEL << "Time to process a range of " << this->_vec.size() << " elements with" << BYEL << " std::vector: " << RES << _time << " us" << std::endl;
        
    } catch (std::exception& e){}

    std::cout << std::endl << YEL << "Initial deque: " << RES;
    for (size_t j = 0; j < this->_deq.size(); j++)
        std::cout << this->_deq[j] << " ";
    std::cout << std::endl;
    try{
        clock_t start = clock();
        std::deque<std::deque<int> > sortedDeq = pairAndSortDeq();
        clock_t end = clock();
        
        std::cout << YEL << "Sorted deque: " << RES;
        for (int i = 0; i < static_cast<int>(sortedDeq.size()); i++){
            for (int j = 0; j < static_cast<int>(sortedDeq[i].size()); j++)
            std::cout << sortedDeq[i][j] << " ";
        }  
        std::cout << std::endl;
        long _time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds
        std::cout << YEL << "Time to process a range of " << this->_deq.size() << " elements with" << BYEL << " std::deque: " << RES << _time << " us" << std::endl;
        
    } catch (std::exception& e){}
    
}

//VECTOR

std::vector<std::vector<int> > PmergeMe::reSizeNextRoundVec(const std::vector<std::vector<int> >& recGroups, size_t gSize)
{
    std::vector<std::vector<int> > reSizedGroups;
    //for each group within recursived group
    for (size_t i = 0; i < recGroups.size(); ++i) {
        const std::vector<int>& prevGrouping = recGroups[i];
        size_t size = prevGrouping.size();
        //if group has grouping size - divide into half and push
        if (size >= 2 * gSize) {
            reSizedGroups.push_back(std::vector<int>(prevGrouping.begin(), prevGrouping.begin() + gSize));
            reSizedGroups.push_back(std::vector<int>(prevGrouping.begin() + gSize, prevGrouping.begin() + (2 * gSize)));
            //Extra tail - shouldn't happen
            if (size > 2 * gSize) {
                reSizedGroups.push_back(std::vector<int>(prevGrouping.begin() + 2 * gSize, prevGrouping.end()));
            }
        }
        //if group has exactly half grouping size (size we're fitting into now) - push
        else if (size == gSize) {
            reSizedGroups.push_back(prevGrouping);
        }
        //if group has more than half grouping size - push half first and then remainder
        else if (size >= gSize){
                reSizedGroups.push_back(std::vector<int>(prevGrouping.begin(), prevGrouping.begin() + gSize));
                reSizedGroups.push_back(std::vector<int>(prevGrouping.begin() + gSize, prevGrouping.end()));
        }
        //if group has less than half grouping size - push it all (remainder)
        else {
              reSizedGroups.push_back(prevGrouping);
        }
    }
    return reSizedGroups;
}

std::vector<int> PmergeMe::jacobSthalSeqVec(size_t max){
    std::vector<int> jsSequence;
    
    if (max == 0)
        return jsSequence;
    if (max >= 1)
        jsSequence.push_back(1);
    if (max >= 2){
        if (3 <= static_cast<int>(max))
            jsSequence.push_back(3);       
    }
        
    for (size_t i = 2; ; i++){
        if (jsSequence.size() < 2)
            break;
        
        int a = jsSequence[i - 1];
        int b = jsSequence[i - 2];
        int next = a + 2 * b;

        if (next > static_cast<int>(max))
            break;
        jsSequence.push_back(next);
    }
    
    return jsSequence;
}

size_t PmergeMe::binarySearchVec(std::vector<std::vector<int> >& main, std::vector<int> pendElm){
    if (pendElm.empty())
        return main.size();
    
    int key = pendElm.back(); // last val of elm we're working on
    size_t low = 0;
    size_t high = main.size();

    while (low < high){
        size_t mid = (low + high) / 2;
        int midKey = main[mid].back(); // last val of mid elm
        
        if (midKey < key)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

std::vector<std::vector<int> > PmergeMe::pairAndSortVec(){
    std::vector<std::vector<int> > groups;

    for (size_t i = 0; (i + 1) < this->_vec.size(); i += 2){
        std::vector<int> pair;
        int a = this->_vec[i];
        int b = this->_vec[i + 1];

        if (a < b){
            pair.push_back(a);
            pair.push_back(b);
        }
        else{
            pair.push_back(b);
            pair.push_back(a);
        }
        groups.push_back(pair);
    }
    
    if (this->_vec.size() % 2 != 0){
        std::vector<int> oddNb;
        oddNb.push_back(this->_vec.back());
        groups.push_back(oddNb);
    }
    
    if (this->_debug){
        std::cout << BGRN << "Grouping level 1: " << RES;
        for (int i = 0; i < static_cast<int>(groups.size()); i++){
            for (int j = 0; j < static_cast<int>(groups[i].size()); j++)
                std::cout << groups[i][j] << " ";
        }
        std::cout << std::endl;   
    }

    std::vector<std::vector<int> > nextRound = vecRecursiveSorting(groups, 1, 1);
    
    groups = unfoldAndGroupVec(reSizeNextRoundVec(nextRound, 1), 1, 1, 1);

    return groups;
}

std::vector<std::vector<int> > PmergeMe::vecRecursiveSorting(std::vector<std::vector<int> > groups, int lvl, size_t gSize){
        
    std::vector<std::vector<int> > nextRound;
    lvl++;

    for (size_t i = 0; (i + 1) < groups.size(); i += 2){
        std::vector<int> A = groups[i];
        std::vector<int> B = groups[i + 1];

        if (A.back() > B.back() && (A.size() == B.size()))
            std::swap(A, B);

        std::vector<int> jointGroup;
        jointGroup.insert(jointGroup.end(), A.begin(), A.end());
        jointGroup.insert(jointGroup.end(), B.begin(), B.end());
        nextRound.push_back(jointGroup);
    }

    if (groups.size() % 2 != 0)
        nextRound.push_back(groups.back());

    if (this->_debug){
        std::cout << BGRN << "Grouping level " << lvl << ": " <<RES;
        for (int i = 0; i < static_cast<int>(groups.size()); i++){
            for (int j = 0; j < static_cast<int>(groups[i].size()); j++)
                std::cout << groups[i][j] << " ";
            std::cout << " . ";
        }
        std::cout << std::endl;
    }

    if (!(nextRound.size() < 2 || (nextRound[0].size() != nextRound[1].size()))){
        std::vector<std::vector<int> > recGroups = vecRecursiveSorting(nextRound, lvl, (gSize * 2));
        groups = reSizeNextRoundVec(recGroups, (gSize * 2));
    }
    
    return unfoldAndGroupVec(groups, gSize, lvl, 0);
}

std::vector<std::vector<int> > PmergeMe::unfoldAndGroupVec(std::vector<std::vector<int > > groups, size_t gSize, int lvl, int flag){
    
    std::vector<std::vector<int> > main;
    std::vector<std::vector<int> > pend;
    std::vector<std::vector<int> > nonPart;

    if (this->_debug){
         std::cout << BRED << "Reordered groups lvl " << lvl << ": ";
        for (int i = 0; i < static_cast<int>(groups.size()); i++){
            for (int j = 0; j < static_cast<int>(groups[i].size()); j++)
                std::cout << groups[i][j] << " ";
            std::cout << " . ";
        }
        std::cout << RES << std::endl;   
    }
    
    if (!flag){ //recursive case
        for (int i = 0; i < static_cast<int>(groups.size()); i++){
            if (groups[i].size() == (gSize * 2)){
                if ((i == 0) || ((i % 2) != 0))
                    main.push_back(groups[i]);
                else
                    pend.push_back(groups[i]);
            }
            else
                nonPart.push_back(groups[i]);
        }   
    }
    else{ //last unfold - lvl 1
        for (int i = 0; i < static_cast<int>(groups.size()); i++){
            if ((i == 0) || ((i % 2) != 0))
                main.push_back(groups[i]);
            else
                pend.push_back(groups[i]);
        }
    }

    if (this->_debug){
        std::cout << BGRN << "Main lvl " << lvl << ": " <<RES;
        for (int i = 0; i < static_cast<int>(main.size()); i++){
            for (int j = 0; j < static_cast<int>(main[i].size()); j++)
                std::cout << main[i][j] << " ";
            std::cout << " . ";
        }
        std::cout << std::endl;

        std::cout << BGRN << "Pend lvl " << lvl << ": " <<RES;
        for (int i = 0; i < static_cast<int>(pend.size()); i++){
            for (int j = 0; j < static_cast<int>(pend[i].size()); j++)
                std::cout << pend[i][j] << " ";
            std::cout << " . ";
        }
        std::cout << std::endl;
        
        std::cout << BGRN << "NonPart lvl " << lvl << ": " <<RES;
        for (int i = 0; i < static_cast<int>(nonPart.size()); i++){
            for (int j = 0; j < static_cast<int>(nonPart[i].size()); j++)
                std::cout << nonPart[i][j] << " ";
                std::cout << " . ";
        }
        std::cout << std::endl;
    }

    if (!pend.empty()){
        std::vector<int> jsSequence = jacobSthalSeqVec(pend.size());
        
        if (jsSequence.empty() || jsSequence.back() < static_cast<int>(pend.size()))
            jsSequence.push_back(static_cast<int>(pend.size()));
        
        // Build explicit insertion order (indices into pend, 0-based).
        // For each groupStart (a cumulative count), push indices [last .. groupStart-1],
        // but we push them in descending order inside each batch (groupStart-1 ... last).
        std::vector<size_t> insertOrder;
        size_t last = 0; //index of last inserted element
        
        for (size_t k = 0; k < jsSequence.size(); ++k){
            size_t insertionLimit = static_cast<size_t>(jsSequence[k]); //index of where up to we want to insert
            
            if (insertionLimit > pend.size())
                insertionLimit = pend.size();
            
            for (size_t j = insertionLimit; j > last; --j){ 
                insertOrder.push_back(j - 1);
            }      
            last = insertionLimit; //next batch will start where last ended
        }
        
        // Perform insertions in the right order.
        for (size_t idx = 0; idx < insertOrder.size(); ++idx){
            size_t pendIndex = insertOrder[idx];
            
            if (pendIndex >= pend.size())
                continue;
            
            size_t pos = binarySearchVec(main, pend[pendIndex]);
            main.insert(main.begin() + pos, pend[pendIndex]);
        }
    }
    
    for (size_t i = 0; i < nonPart.size(); i++)
        main.push_back(nonPart[i]);
    groups = main;
    
    if (this->_debug){
        std::cout << BCYA << "Groups after insertion lvl " << lvl << ": ";
        for (int i = 0; i < static_cast<int>(groups.size()); i++){
            for (int j = 0; j < static_cast<int>(groups[i].size()); j++)
                std::cout << groups[i][j] << " ";
            std::cout << " . ";
        }
        std::cout << RES << std::endl;
    }
    
    return groups;
}

//DEQUE
std::deque<std::deque<int> > PmergeMe::reSizeNextRoundDeq(const std::deque<std::deque<int> >& recGroups, size_t gSize)
{
    std::deque<std::deque<int> > reSizedGroups;
    //for each group within recursived group
    for (size_t i = 0; i < recGroups.size(); ++i) {
        const std::deque<int>& prevGrouping = recGroups[i];
        size_t size = prevGrouping.size();
        //if group has grouping size - divide into half and push
        if (size >= 2 * gSize) {
            reSizedGroups.push_back(std::deque<int>(prevGrouping.begin(), prevGrouping.begin() + gSize));
            reSizedGroups.push_back(std::deque<int>(prevGrouping.begin() + gSize, prevGrouping.begin() + (2 * gSize)));
            //Extra tail - shouldn't happen
            if (size > 2 * gSize) {
                reSizedGroups.push_back(std::deque<int>(prevGrouping.begin() + 2 * gSize, prevGrouping.end()));
            }
        }
        //if group has exactly half grouping size (size we're fitting into now) - push
        else if (size == gSize) {
            reSizedGroups.push_back(prevGrouping);
        }
        //if group has more than half grouping size - push half first and then remainder
        else if (size >= gSize){
                reSizedGroups.push_back(std::deque<int>(prevGrouping.begin(), prevGrouping.begin() + gSize));
                reSizedGroups.push_back(std::deque<int>(prevGrouping.begin() + gSize, prevGrouping.end()));
        }
        //if group has less than half grouping size - push it all (remainder)
        else {
              reSizedGroups.push_back(prevGrouping);
        }
    }
    return reSizedGroups;
}

std::deque<int> PmergeMe::jacobSthalSeqDeq(size_t max){
    std::deque<int> jsSequence;
    
    if (max == 0)
        return jsSequence;
    if (max >= 1)
        jsSequence.push_back(1);
    if (max >= 2){
        if (3 <= static_cast<int>(max))
            jsSequence.push_back(3);       
    }
        
    for (size_t i = 2; ; i++){
        if (jsSequence.size() < 2)
            break;
        
        int a = jsSequence[i - 1];
        int b = jsSequence[i - 2];
        int next = a + 2 * b;

        if (next > static_cast<int>(max))
            break;
        jsSequence.push_back(next);
    }
    
    return jsSequence;
}

size_t PmergeMe::binarySearchDeq(std::deque<std::deque<int> >& main, std::deque<int> pendElm){
    if (pendElm.empty())
        return main.size();
    
    int key = pendElm.back(); // last val of elm we're working on
    size_t low = 0;
    size_t high = main.size();

    while (low < high){
        size_t mid = (low + high) / 2;
        int midKey = main[mid].back(); // last val of mid elm
        
        if (midKey < key)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

std::deque<std::deque<int> > PmergeMe::pairAndSortDeq(){
    std::deque<std::deque<int> > groups;

    for (size_t i = 0; (i + 1) < this->_deq.size(); i += 2){
        std::deque<int> pair;
        int a = this->_deq[i];
        int b = this->_deq[i + 1];

        if (a < b){
            pair.push_back(a);
            pair.push_back(b);
        }
        else{
            pair.push_back(b);
            pair.push_back(a);
        }
        groups.push_back(pair);
    }
    
    if (this->_deq.size() % 2 != 0){
        std::deque<int> oddNb;
        oddNb.push_back(this->_deq.back());
        groups.push_back(oddNb);
    }
    
    if (this->_debug){
        std::cout << BGRN << "Grouping level 1: " << RES;
        for (int i = 0; i < static_cast<int>(groups.size()); i++){
            for (int j = 0; j < static_cast<int>(groups[i].size()); j++)
                std::cout << groups[i][j] << " ";
        }
        std::cout << std::endl;   
    }

    std::deque<std::deque<int> > nextRound = deqRecursiveSorting(groups, 1, 1);
    
    groups = unfoldAndGroupDeq(reSizeNextRoundDeq(nextRound, 1), 1, 1, 1);

    return groups;
}

std::deque<std::deque<int> > PmergeMe::deqRecursiveSorting(std::deque<std::deque<int> > groups, int lvl, size_t gSize){
        
    std::deque<std::deque<int> > nextRound;
    lvl++;

    for (size_t i = 0; (i + 1) < groups.size(); i += 2){
        std::deque<int> A = groups[i];
        std::deque<int> B = groups[i + 1];

        if (A.back() > B.back() && (A.size() == B.size()))
            std::swap(A, B);

        std::deque<int> jointGroup;
        jointGroup.insert(jointGroup.end(), A.begin(), A.end());
        jointGroup.insert(jointGroup.end(), B.begin(), B.end());
        nextRound.push_back(jointGroup);
    }

    if (groups.size() % 2 != 0)
        nextRound.push_back(groups.back());

    if (this->_debug){
        std::cout << BGRN << "Grouping level " << lvl << ": " <<RES;
        for (int i = 0; i < static_cast<int>(groups.size()); i++){
            for (int j = 0; j < static_cast<int>(groups[i].size()); j++)
                std::cout << groups[i][j] << " ";
            std::cout << " . ";
        }
        std::cout << std::endl;
    }

    if (!(nextRound.size() < 2 || (nextRound[0].size() != nextRound[1].size()))){
        std::deque<std::deque<int> > recGroups = deqRecursiveSorting(nextRound, lvl, (gSize * 2));
        groups = reSizeNextRoundDeq(recGroups, (gSize * 2));
    }
    
    return unfoldAndGroupDeq(groups, gSize, lvl, 0);
}

std::deque<std::deque<int> > PmergeMe::unfoldAndGroupDeq(std::deque<std::deque<int > > groups, size_t gSize, int lvl, int flag){
    
    std::deque<std::deque<int> > main;
    std::deque<std::deque<int> > pend;
    std::deque<std::deque<int> > nonPart;

    if (this->_debug){
         std::cout << BRED << "Reordered groups lvl " << lvl << ": ";
        for (int i = 0; i < static_cast<int>(groups.size()); i++){
            for (int j = 0; j < static_cast<int>(groups[i].size()); j++)
                std::cout << groups[i][j] << " ";
            std::cout << " . ";
        }
        std::cout << RES << std::endl;   
    }
    
    if (!flag){ //recursive case
        for (int i = 0; i < static_cast<int>(groups.size()); i++){
            if (groups[i].size() == (gSize * 2)){
                if ((i == 0) || ((i % 2) != 0))
                    main.push_back(groups[i]);
                else
                    pend.push_back(groups[i]);
            }
            else
                nonPart.push_back(groups[i]);
        }   
    }
    else{ //last unfold - lvl 1
        for (int i = 0; i < static_cast<int>(groups.size()); i++){
            if ((i == 0) || ((i % 2) != 0))
                main.push_back(groups[i]);
            else
                pend.push_back(groups[i]);
        }
    }

    if (this->_debug){
        std::cout << BGRN << "Main lvl " << lvl << ": " <<RES;
        for (int i = 0; i < static_cast<int>(main.size()); i++){
            for (int j = 0; j < static_cast<int>(main[i].size()); j++)
                std::cout << main[i][j] << " ";
            std::cout << " . ";
        }
        std::cout << std::endl;

        std::cout << BGRN << "Pend lvl " << lvl << ": " <<RES;
        for (int i = 0; i < static_cast<int>(pend.size()); i++){
            for (int j = 0; j < static_cast<int>(pend[i].size()); j++)
                std::cout << pend[i][j] << " ";
            std::cout << " . ";
        }
        std::cout << std::endl;
        
        std::cout << BGRN << "NonPart lvl " << lvl << ": " <<RES;
        for (int i = 0; i < static_cast<int>(nonPart.size()); i++){
            for (int j = 0; j < static_cast<int>(nonPart[i].size()); j++)
                std::cout << nonPart[i][j] << " ";
                std::cout << " . ";
        }
        std::cout << std::endl;
    }

    if (!pend.empty()){
        std::vector<int> jsSequence = jacobSthalSeqVec(pend.size());
        
        if (jsSequence.empty() || jsSequence.back() < static_cast<int>(pend.size()))
            jsSequence.push_back(static_cast<int>(pend.size()));
        
        // Build explicit insertion order (indices into pend, 0-based).
        // For each groupStart (a cumulative count), push indices [last .. groupStart-1],
        // but we push them in descending order inside each batch (groupStart-1 ... last).
        std::vector<size_t> insertOrder;
        size_t last = 0; //index of last inserted element
        
        for (size_t k = 0; k < jsSequence.size(); ++k){
            size_t insertionLimit = static_cast<size_t>(jsSequence[k]); //index of where up to we want to insert
            
            if (insertionLimit > pend.size())
                insertionLimit = pend.size();
            
            for (size_t j = insertionLimit; j > last; --j){ 
                insertOrder.push_back(j - 1);
            }      
            last = insertionLimit; //next batch will start where last ended
        }
        
        // Perform insertions in the right order.
        for (size_t idx = 0; idx < insertOrder.size(); ++idx){
            size_t pendIndex = insertOrder[idx];
            
            if (pendIndex >= pend.size())
                continue;
            
            size_t pos = binarySearchDeq(main, pend[pendIndex]);
            main.insert(main.begin() + pos, pend[pendIndex]);
        }
    }
    
    for (size_t i = 0; i < nonPart.size(); i++)
        main.push_back(nonPart[i]);
    groups = main;
    
    if (this->_debug){
        std::cout << BCYA << "Groups after insertion lvl " << lvl << ": ";
        for (int i = 0; i < static_cast<int>(groups.size()); i++){
            for (int j = 0; j < static_cast<int>(groups[i].size()); j++)
                std::cout << groups[i][j] << " ";
            std::cout << " . ";
        }
        std::cout << RES << std::endl;
    }
    
    return groups;
}