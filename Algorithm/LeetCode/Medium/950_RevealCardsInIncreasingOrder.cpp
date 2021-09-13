/*
https://leetcode.com/problems/reveal-cards-in-increasing-order/
sequence is: take 1, move 1 to back...

reverse engineer:
put 17

take last to front, put next one to front

2, 3, 5, 7, 11, 13, 17

-> 17
-> 13, 17
-> 11, 17, 13
-> 7, 13, 11, 17
-> 5, 17, 7, 13, 11
-> 3, 11, 5, 17, 7, 13
-> 2 ,13, 5, 11, 5, 17, 7

*/

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        sort(deck.begin(), deck.end());
        
        if(deck.size() < 3){
            return deck;
        }
        
        deque<int> dq;
        dq.push_back(deck.back());
        deck.pop_back();
        
        while(!deck.empty()){
            int temp = dq.back();
            dq.pop_back();
            dq.push_front(temp);
            dq.push_front(deck.back());
            deck.pop_back();
        }
        
        return vector<int>(dq.begin(), dq.end());
        
    }
};