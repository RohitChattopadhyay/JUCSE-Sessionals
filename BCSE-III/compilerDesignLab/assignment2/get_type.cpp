#include <bits/stdc++.h>
#include "get_type.h"
using namespace std;

set <string> keywords = {"else","if","for","int","float","void","return"};
set <string> arithop = {"+", "-", "*", "/"};
set <string> relop = {"<", ">"};
set <string> assignop = {"="};
set <string> punctuation = {";", ",", "(", ")", "{", "}"};

int is_alphabet(char c)
{
	return ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) || c=='_';
}
int is_number(char c)
{
	return ((c >= '0') && (c <= '9'));
}

/* Performs state transition based on input. Returns a string corresponding to the final state reached
State 0 - Start state
State 1 - integer(inum)
State 2 - float(num)
State 3 - identifier(id)
State 4 - error
*/
string get_state(string s)
{
	int state = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(state == 0) 
		{
			if(is_number(s[i]))
				state = 1;
			else if(s[i] == '.')
				state = 2;
			else if(is_alphabet(s[i]))
				state = 3;
			else 
				state = 4;
			continue;
		}
		else if(state == 1)
		{
			if(is_number(s[i]))
				state = 1;
			else if(s[i] == '.')
				state = 2;
			else
				state = 4;
			continue;
		}
		else if(state == 2)
		{
			if(is_number(s[i]))
				state = 2;
			else
				state = 4;
			continue;
		}
		else if(state == 3)
		{
			if(is_number(s[i]) || is_alphabet(s[i]))
				state = 3;
			else
				state = 4;
			continue;
		}

	}

	switch(state)
	{
		
		case 1: return "inum"; break;
		case 2: return "num"; break;
		case 3: return "id"; break;
		case 4: return "error"; break;
		default: return NULL;
	}
}


string getType(string s)
{
	if(keywords.find(s) != keywords.end())
		return "keyword";
	if(arithop.find(s) != arithop.end())
		return "arithop";
	if(relop.find(s) != relop.end())
		return "relop";
	if(assignop.find(s) != assignop.end())
		return "assignop";
	if(punctuation.find(s) != punctuation.end())
		return "punctuation";

	return get_state(s);
	
}
