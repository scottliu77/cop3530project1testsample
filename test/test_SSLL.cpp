#include "catch.hpp"

#include "SSLL.h"	
#include "PSLL.h"
#include "SDAL.h"
#include "CDAL.h"
#include "CBL.h"

#include <iostream>

bool equals(const char& a, const char& b) {
	return a == b;
}

SCENARIO ("INTERFACE TEST") {
	GIVEN ("List of characters") {

		cop3530::List<char> * list  = new cop3530::SSLL<char>();
		// cop3530::List<char> * list = new cop3530::PSLL<char>();
		// cop3530::List<char> * list = new cop3530::SDAL<char>();
		// cop3530::List<char> * list = new cop3530::CDAL<char>();
		// cop3530::List<char> * list = new cop3530::CBL<char>();

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
		WHEN ("Pop front is called") {
                        char front = list->pop_front();
                        THEN ("Item should be D") {
                                REQUIRE(front == 'D');
                        }
                }
                WHEN ("Pop back is called") {
                        char back = list->pop_back();
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
			size_t len = list->length();
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
			char item = list->remove(0);
			size_t len = list->length();
			THEN ("Item should be D") {
				REQUIRE(item == 'D');
			}
			THEN ("Length should be 3") {
				REQUIRE(len == 3);
			}
		}
		WHEN ("Checking if the list contains element B") {
			bool b = list->contains('B', equals);
			THEN ("It should return true") {
				REQUIRE (b);
			}
		}
		WHEN ("Contents is called on array") {
			char * arr = list->contents();
			THEN ("Array items should be [D, A, B, C]") {
				char expected[4] = {'D', 'A', 'B', 'C'};
				for(size_t i = 0; i < list->length(); i++) {
					REQUIRE(*(arr+i) == expected[i]);
				}
			}
			delete[] arr;
		}
		WHEN ("Clear is called") {
			list->clear();
			size_t len = list->length();
			THEN ("Length should be 0") {
				REQUIRE(len == 0);
			}
		}

		delete list;
	}
}


class C {
	public:
		int a;
		C() : C(0) {}
		C(int a) : a(a) {}
		inline bool operator == (const C& c) const {
 			return a == c.a;
		}
		inline friend std::ostream& operator << (std::ostream& stream, const C& c) {
			return stream << c.a;
        	}
};

SCENARIO ("TEST 1") {
	GIVEN ("List of objects") {

		cop3530::List<C> * list = new cop3530::SSLL<C>();
		// cop3530::List<C> * list = new cop3530::PSLL<C>();
		// cop3530::List<C> * list = new cop3530::SDAL<C>();
		// cop3530::List<C> * list = new cop3530::CDAL<C>();
		// cop3530::List<C> * list = new cop3530::CBL<C>();
		
		C a(10), b(20), c(30);
		list->insert(a, 0);
		list->insert(b, 0);
		list->insert(c, 0);
		
		WHEN ("List length is checked") {
			size_t len = list->length();
			THEN ("Length should be 3") {
				REQUIRE(len == 3);
			}
		}
		WHEN ("Peek front is called") {
			C front = list->peek_front();
			THEN ("Item at the front should be 9") {
				REQUIRE(front == c);
			}
		}
		WHEN ("Peek back is called") {
			C back = list->peek_back();
			THEN ("Item at the back should be 0") {
				REQUIRE(back == a);
			}
		}
		
		delete list;
	}
}
