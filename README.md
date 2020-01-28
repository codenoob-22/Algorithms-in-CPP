# Algorithms-in-CPP
Solutions i've written for problems in programming competitions or snippets i find worth keeping.

## backtracking:-
currently i am attempting some good problems to polish my recursive thinking. 
### my experience with backtracking:-
concept:- build a recursive function that tries every solution, rejects and moves on to other parts.

things to take care of:- 
1) it is a systematic generating method that avoids repetitions and missing any possible right solution. This property makes it ideal for solving combinatorial problems such as combination and permutation which requires us to enumerate all possible solutions.
2) in the process of working with partial solutions, we can evaluate the partial solution and prune branches that would never lead to the acceptable complete solution: either it is invalid configuration, or it is worse than known possible complete solution.

## dynamic programming:-
this is one of the most tough topics to master. But, there are some insights which make me comfortable with solving Dynamic programming problems;

### my experience with dynamic programming:-

conceptually while calculating a recursive function we are going down the recursion tree from root to node. there can be significant optimization if we cache the data of intermediate nodes so that we dont have to go below in their subtree to calculate the value again. again we will have to optimally chose the point whre you have to chose caching that you dont get too much space complexity as well.

types of programming problems we see :- 

Minimum (Maximum) Path to Reach a Target,

Distinct Ways,

Merging Intervals,

DP on Strings,

Decision Making,

 refer this source: https://leetcode.com/discuss/general-discussion/458695/dynamic-programming-patterns#DP-on-Strings
