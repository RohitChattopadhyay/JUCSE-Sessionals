#include<bits/stdc++.h>
#include "get_type.h"
using namespace std;
char delimiters[] = {' ', '\n', '\t', '+', '-', '*', '/', '>', '<', '=', ';', ',', '(', ')', '{', '}' };

class Token
{
	private:
		static int count;
		int token_id;
		string lexeme;
		string token_type;
		int rowno;
		int colno;

	public:
		Token(string l, int r, int c)
		{
			count++;
			token_id = count;
			lexeme = l; rowno = r; colno = c;
			token_type = getType(lexeme);
		}

		void display()
		{
			cout << setw(15) << token_id << "|" << setw(15) << token_type << "|" << setw(15) << lexeme << "|" << setw(15) << rowno << "|" << setw(15) << colno << "|" << endl;
		}

};

int Token::count = 0;

class Symbol_table
{
	public:
	vector<Token> st;

	void insert(Token t)
	{
		st.push_back(t);
	}

	void display()
	{
		for(int j = 0; j < 80; j++)
		{
			cout << "_";
		}
		cout << endl;
		cout << setw(16) << "Token ID|" << setw(16) << "Token type|" << setw(16) << "Lexeme|" << setw(16) << "Row|" << setw(16) << "Column|" << endl;
		for(int i = 0; i < st.size(); i++)
		{
			for(int j = 0; j < 80; j++)
			{
				if(j % 16 == 15) cout << "|";
				else cout << "_";
			}
			cout << endl;
			st[i].display();	
		}
		for(int j = 0; j < 80; j++)
		{
			if(j % 16 == 15) cout << "|";
			else cout << "_";
		}
		cout << endl;
	}
};

// Function to check whether a character is a delimiter
bool is_delimiter(char ch)
{
	for(int i = 0; i < 16; i++)
	{
		if(ch == delimiters[i])
			return true;
	}
	return false;
}

int main()
{	
	fstream fin;
	fin.open("input.txt", ios::in | ios::binary);
	string word = "";
	char ch;
	
	fin.get(ch);
	Symbol_table symtab;
	int row = 0;
	int col = 0;
	int start_col = 0;
	// Loop for reading from input file and tokenizing the words.
	while(!fin.eof())
	{
		// Checking for comments 
		if(ch == '/')
		{
			
			fin.get(ch);
			if(ch == '/')
			{
				while(ch != '\n' && !fin.eof())
				{
					fin.get(ch);
				}
				if(fin.eof()) break;
			}
			else if(ch == '*')
			{
				col += 1;
				while(1)
				{
					fin.get(ch);
					if(fin.eof()) break;
					else if(ch == '*')
					{
						fin.get(ch);
						if(fin.eof()) break;
						if(ch == '/') break;
						else
						{	
							fin.seekg(-1, ios::cur);
						}
					}
					else if(ch == '\n')
					{
						row++; col = 0;
					}
				}
				if(fin.eof()) break;
				fin.get(ch);
			}
			else
			{
				fin.seekg(-1, ios::cur);
			}
		}	
		if(is_delimiter(ch))
		{
			// Inserting the word into symbol table
			if(word != "")
			{
				Token t(word, row, start_col);
				symtab.insert(t);

			}
			// Inserting the symbol into symbol table
			if(ch != ' ' && ch != '\n' && ch != '\t')
			{
				string str(1, ch);
				Token t(str, row, col);
				symtab.insert(t);
			}

			word = "";
			start_col = col + 1;

			
		}
		else
		{
			word += ch;
			
		}
		// Updating row and col no in case of new line
		if(ch == '\n')
		{
			row++;
			col = 0;
			start_col = 0;
		}
		else if(ch == '\t')
		{
			col += 4;
			start_col = col;

		}
		else
			col++;
		fin.get(ch);
	} 
	if(word != "")
	{
		Token t(word, row, start_col);
		symtab.insert(t);
	}	
	symtab.display();
	fin.close();
	
}
