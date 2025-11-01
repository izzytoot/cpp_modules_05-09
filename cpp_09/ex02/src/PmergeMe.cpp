/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:39:21 by icunha-t          #+#    #+#             */
/*   Updated: 2025/11/01 14:11:57 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& src): _dequeBefore(src._dequeBefore), _vectorBefore(src._vectorBefore),_dequeAfter(src._dequeAfter), _vectorAfter(src._vectorAfter) {}

PmergeMe& PmergeMe::operator= (const PmergeMe& src){
    if (this != &src){
        this->_dequeBefore = src._dequeBefore;
        this->_vectorBefore = src._vectorBefore;
        this->_dequeAfter = src._dequeAfter;
        this->_vectorAfter = src._vectorAfter;
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
            this->_vectorBefore.push_back(currNb);
            this->_dequeBefore.push_back(currNb);   
        }
        else
            throw std::runtime_error(RED "Error: empty argument" RES);
    }
}

std::deque<std::deque<std::deque<_elm> > > PmergeMe::dequeRecursivePairing(std::deque<std::deque<std::deque<_elm> > >& deqMetaData, std::deque<std::deque<_elm> > groups, int rlvl, size_t size){
 
        
    if (groups.size() < 2 || (groups[0].size() != groups[1].size()))
        return deqMetaData;
    
    size *= 2;
    ++rlvl; // current recursion level for merged groups
    std::deque<std::deque<_elm> > nextRound;
    int nextGlvl = 0; // group id counter for this recursion level

    for (size_t i = 0; i + 1 < groups.size(); i += 2){
        std::deque<_elm> X = groups[i];
        std::deque<_elm> Y = groups[i + 1];
        
        if (X.size() != Y.size()){
            ++nextGlvl;
            
            for (std::deque<_elm>::iterator it = X.begin(); it != X.end(); ++it) 
                it->lableChar = 'b';
            for (std::deque<_elm>::iterator it = Y.begin(); it != Y.end(); ++it) 
                it->lableChar = 'p';

            std::deque <_elm> jointGroup;
            jointGroup.insert(jointGroup.end(), X.begin(), X.end());
            jointGroup.insert(jointGroup.end(), Y.begin(), Y.end());

            for (std::deque<_elm>::iterator it = jointGroup.begin(); it != jointGroup.end(); ++it) {
                it->rlvl = rlvl;
                it->lableInt = nextGlvl;
            }

            nextRound.push_back(jointGroup);
            break;
        }

        if (!X.empty() && !Y.empty()) {
            // Ensure X has the smaller block-max (so X comes first)
            if (X.back().val > Y.back().val) {
                std::swap(X, Y);   // now X has smaller back
            }

            // Now label whole first block as 'b' and second as 'a'
            for (std::deque<_elm>::iterator it = X.begin(); it != X.end(); ++it) {
                it->lableChar = 'b';
            }
            for (std::deque<_elm>::iterator it = Y.begin(); it != Y.end(); ++it) {
                it->lableChar = 'a';
            }
        }
            
        ++nextGlvl;
        std::deque <_elm> jointGroup;
        jointGroup.insert(jointGroup.end(), X.begin(), X.end());
        jointGroup.insert(jointGroup.end(), Y.begin(), Y.end());

        for (std::deque<_elm>::iterator it = jointGroup.begin(); it != jointGroup.end(); ++it) {
            it->rlvl = rlvl;
            it->lableInt = nextGlvl;
        }
        
        nextRound.push_back(jointGroup);
    }

    if (groups.size() % 2 != 0){
        std::deque<_elm> oddGr = groups.back();
        ++nextGlvl;

        for (std::deque<_elm>::iterator it = oddGr.begin(); it != oddGr.end(); ++it) {
            it->rlvl = rlvl;
            it->lableInt = nextGlvl;
            if (oddGr.size() != size)
                it->lableChar = 'p';
            else
                it->lableChar = 'b';
        }
        
        nextRound.push_back(oddGr);
    }
        
    deqMetaData.push_back(nextRound);    
    return dequeRecursivePairing(deqMetaData, nextRound, rlvl, size);     
}

std::deque<std::deque<std::deque<_elm> > > PmergeMe::pairAndSortDeque(){
    std::deque<std::deque<std::deque<_elm> > > deqMetaData;
    std::deque<std::deque<_elm> > groups;
    int glvl = 0; // group id for level 1 pairs (will start at 1)
    int rlvl = 1; // recursion level 1 for initial pairs

    for (size_t i = 0; i + 1 < this->_dequeBefore.size(); i += 2){
        std::deque<_elm> pair;
        _elm x, y;
        glvl++;
        
        x.val = this->_dequeBefore[i];
        y.val = this->_dequeBefore[i + 1];

        // set original pair metadata: keep lableChar ('b' is smaller, 'a' is larger)
        if (x.val < y.val){
            x.lableChar = 'b'; x.lableInt = glvl; x.rlvl = rlvl;
            y.lableChar = 'a'; y.lableInt = glvl; y.rlvl = rlvl;
            pair.push_back(x);
            pair.push_back(y);
        }
        else{
            x.lableChar = 'a'; x.lableInt = glvl; x.rlvl = rlvl;
            y.lableChar = 'b'; y.lableInt = glvl; y.rlvl = rlvl;
            pair.push_back(y);
            pair.push_back(x);
        }
        groups.push_back(pair);
    }
    
    if (this->_dequeBefore.size() % 2 != 0){
        std::deque<_elm> oddNb;
        _elm odd;
        ++glvl;

        odd.val = this->_dequeBefore.back();
        odd.lableChar = 'b';
        odd.lableInt = glvl;
        odd.rlvl = rlvl;
        oddNb.push_back(odd);
        groups.push_back(oddNb);
    }
    
    deqMetaData.push_back(groups);
    deqMetaData = dequeRecursivePairing(deqMetaData, groups, rlvl, 1);
    return deqMetaData;
}

std::vector<std::vector<int> > PmergeMe::vectorRecursivePairing(std::vector<std::vector<int> > groups){
    if (groups.size() < 2)
        return groups;
    
    std::vector<std::vector<int> > nextRound;

    for (size_t i = 0; (i + 1) < groups.size(); i += 2){
        std::vector<int> A = groups[i];
        std::vector<int> B = groups[i + 1];

        if (A.size() != B.size()){
            std::vector <int> jointGroup;
            jointGroup.insert(jointGroup.end(), A.begin(), A.end());
            jointGroup.insert(jointGroup.end(), B.begin(), B.end());

            nextRound.push_back(jointGroup);
            break;
        }

        if (A.back() > B.back())
            std::swap(A, B);

        std::vector<int> jointGroup;
        jointGroup.insert(jointGroup.end(), A.begin(), A.end());
        jointGroup.insert(jointGroup.end(), B.begin(), B.end());
        nextRound.push_back(jointGroup);
    }

    if (groups.size() % 2 != 0)
        nextRound.push_back(groups.back());

    return vectorRecursivePairing(nextRound);
}

std::vector<std::vector<int> > PmergeMe::pairAndSortVector(){
    std::vector<std::vector<int> > groups;

    for (size_t i = 0; (i + 1) < this->_vectorBefore.size(); i += 2){
        std::vector<int> pair;
        int a = this->_vectorBefore[i];
        int b = this->_vectorBefore[i + 1];

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
    
    if (this->_vectorBefore.size() % 2 != 0){
        std::vector<int> oddNb;
        oddNb.push_back(this->_vectorBefore.back());
        groups.push_back(oddNb);
    }
     
    return vectorRecursivePairing(groups);
}

void PmergeMe::sort(){
    std::cout << YEL << "Before for deque: " << RES;
    for (std::deque<int>::const_iterator it = this->_dequeBefore.begin(); it != this->_dequeBefore.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
  
    std::cout << YEL << "Before for vector: " << RES;
    for (size_t j = 0; j < this->_vectorBefore.size(); j++)
        std::cout << this->_vectorBefore[j] << " ";
    std::cout << std::endl;
    
    try{
        clock_t start = clock();
        std::deque< std::deque<std::deque<_elm> > > dqFJPhase1 = pairAndSortDeque();
        //phase 2
        //phase 3
        clock_t end = clock();
        
        std::cout << std::endl;
        for (int i = 0; i < static_cast<int>(dqFJPhase1.size()); i++){
            std::cout << BRED << "recursion phase " << i << RES << std::endl;
            for (int j = 0; j < static_cast<int>(dqFJPhase1[i][j].size()); j++){
                for (int k = 0; k < static_cast<int>(dqFJPhase1[i][j].size()); k++)
                    std::cout << "val:" << BGRN << dqFJPhase1[i][j][k].val << RES << ", " <<  dqFJPhase1[i][j][k].lableChar << dqFJPhase1[i][j][k].lableInt << " | ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        
        std::cout << YEL << "Deque phase 1: " << RES;
        for (int i = 0; i < static_cast<int>(dqFJPhase1.size()); i++){
            if (i != (static_cast<int>(dqFJPhase1.size()) - 1))
                continue;
            for (int j = 0; j < static_cast<int>(dqFJPhase1[i].size()); j++){
                for (int k = 0; k < static_cast<int>(dqFJPhase1[i][j].size()); k++)
                    std::cout << dqFJPhase1[i][j][k].val << " ";
            }
        }
        double _time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds
        std::cout << std::endl;
        std::cout << YEL << "Time to process a range of " << this->_dequeBefore.size() << " elements with" << BYEL << " std::deque: " << RES << _time << " us" << std::endl;
        std::cout << std::endl;
    } catch(std::exception& e){}

    try{
        clock_t start = clock();
        std::vector<std::vector<int> > vecFJPhase1 = pairAndSortVector();
        //phase 2
        //phase 3
        clock_t end = clock();
        
        std::cout << YEL << "Vector phase 1: " << RES;
        for (int i = 0; i < static_cast<int>(vecFJPhase1.size()); i++){
            for (int j = 0; j < static_cast<int>(vecFJPhase1[i].size()); j++)
            std::cout << vecFJPhase1[i][j] << " ";
        }  
        std::cout << std::endl;
        long _time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds
        std::cout << YEL << "Time to process a range of " << this->_vectorBefore.size() << " elements with" << BYEL << " std::vector: " << RES << _time << " us" << std::endl;
        
    } catch (std::exception& e){}
    

}