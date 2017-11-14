#include "catch.hpp"
#include <iostream>
#include "SSLL.h"

SCENARIO ("INTERFACE TEST") {
	GIVEN ("An SSLL of characters is created") {

		cop3530::List<char> *list = new cop3530::SSLL<char>();
		list->insert('A', 0);
		list->insert('B', 1);
		list->push_back('C');
		list->push_front('D');
		list->print(std::cout);

		WHEN ("Peek front is called") {
			char front = list->peek_front();

			THEN ("Item should be D") {
				REQUIRE(front == 'D');
			}
		}
		WHEN ("Peek back is called") {
			char back = list->peek_back();

			THEN ("Item should be C") {
				REQUIRE(back == 'C');
			}
		}
		WHEN ("Replaced is called with item E at position 1") {
			list->replace('E', 1);
			char item = list->item_at(1);
			THEN ("Item at position 1 should be E") {
				REQUIRE( item == 'E');
			}

		}
		WHEN ("List length is checked") {
			int len = list->length();
			THEN ("Length should be 4") {
				REQUIRE( len == 4);
			}
		}
		WHEN ("Checking if list is empty") {
			bool empty = list->is_empty();
			THEN ("It should return false") {
				REQUIRE(!empty);
			}
		}
		WHEN ("Checking if list is full") {
			bool full = list->is_full();
			THEN ("It should return false") {
				REQUIRE(!full);
			}
		}
		WHEN ("Remove is called at position 0") {
			list->print(std::cout);
			char item = list->remove(0);
			int len = list->length();
			list->print(std::cout);
			THEN ("Item should be D") {
				REQUIRE(item == 'D');
			}
			THEN ("Length should be 3") {
				REQUIRE(len == 3);
			}
		}
		WHEN ("Checking if the list contains element B") {
			bool b = list->contains('B', [](const char& a, const char& b) {
        					return a == b;
   				   		});
			THEN ("It should return true") {
				REQUIRE (b);
			}
		}
		WHEN ("Contents is called on array") {
			char * arr = list->contents();
			THEN ("Array items should be [D, A, B, C]") {
				char expected[4] = {'D', 'A', 'B', 'C'};
				for(int i = 0; i < list->length(); i++) {
					REQUIRE(*(arr+i) == expected[i]);
				}
			}
		}
		WHEN ("Clear is called") {
			list->clear();
			int len = list->length();
			THEN ("Length should be 0") {
				REQUIRE(len == 0);
			}
		}

		delete list;
	}
}


SCENARIO ("TEST 1") {
	GIVEN ("An SSLL of integers is created") {

		cop3530::List<int> *list = new cop3530::SSLL<int>();
		for(int i = 0; i < 10; i++) 
			list->insert(i, 0);
		
		WHEN ("List length is checked") {
			int len = list->length();

			THEN ("Length should be 10") {
				REQUIRE(len == 10);
			}
		}
		WHEN ("Peek front is called") {
			int front = list->peek_front();

			THEN ("Item at the front should be 9") {
				REQUIRE(front == 9);
			}
		}
		WHEN ("Peek back is called") {
			int back = list->peek_back();

			THEN ("Item at the back should be 0") {
				REQUIRE(back == 0);
			}
		}
		
		delete list;
	}
}