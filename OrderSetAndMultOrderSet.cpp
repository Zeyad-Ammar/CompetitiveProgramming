/*
the ordered_set is same set and multiset but give u more functions.
How to use : 
define an object like this : ordered_set st or stMultiOrderedSet mst ;
then you can deal with it as you deal with set 
 
Extra Functions : 

 
find_by_order(k) .. O(log(N))=> give u access elements in specific idx
It returns an iterator to the kth element (counting from zero) in the set in O(log(n)) time.
To find the first element k must be zero.
Let us assume we have a set s : {1, 5, 6, 17, 88}, 
then :
*(s.find_by_order(2)) : 3rd element in the set is 6
*(s.find_by_order(4)) : 5th element in the set is 88
 
order_of_key(k).. O(log(N))//=> the numbers less than number k in the set even if it not exist.
U can think on it it's "idx of this element" in case it exist or we will add it
It returns to the number of items that are strictly smaller than our item k in O(log(n)) time.
Let us assume we have a set s : {1, 5, 6, 17, 88}
then :
s.order_of_key(6) : Count of elements strictly smaller than 6 is 2.
s.order_of_key(25) : Count of elements strictly smaller than 25 is 4.

*/

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
namespace __gnu_pbds{
	typedef tree<pair<long long,long long>,
			null_type,
			less<pair<long long,long long>>,
	rb_tree_tag,
	tree_order_statistics_node_update> ordered_set;
}

using namespace __gnu_pbds;

class stMultiOrderedSet {
private:
	typedef tree<long long,
			null_type,
			less_equal<long long>,
			rb_tree_tag,
			tree_order_statistics_node_update> ordered_set;

	ordered_set s;

public:

	void insert(long long x) {//insert value
		s.insert(x);
	}


	bool isExist(long long x) {//check the existing of a value?
		if (s.upper_bound(x) == s.end()) {
			return false;
		}
		return (*s.upper_bound(x)) == x;
	}

	void erase(long long x) { //erase an instance of a value
		if (isExist(x)) {
			s.erase(s.upper_bound(x));
		}
	}

	long long idx(long long x) {//index of existing value
		if (!isExist(x)) {
			return -1;
		}
		return s.order_of_key(x);
	}
	//can't understand what's it does
	long long LastIdx(long long x) {//return the  index of the last instance of value
		if (!isExist(x)) {
			return -1;
		}
		if (*s.find_by_order(s.size() - 1) == x) {
			return s.size() - 1;
		}
		return idx(*s.lower_bound(x)) - 1;
	}

	long long value(long long index) {//find the value in an index
		return *s.find_by_order(index);
	}

	long long count(long long x) {//count the number of instances for specific value
		if (!isExist(x)) {
			return 0;
		}
		return LastIdx(x) - idx(x) + 1;
	}

	void clear() {//clear the set
		s.clear();
	}

	long long size(){//return the size of the set
		return s.size();
	}

	long long lower_bound(long long x)//return the first equal or greater element than x
	{
		return *s.upper_bound(x);
	}

	long long upper_bound(long long x)//return the first greater element than x
	{

		return *s.lower_bound(x);
	}

	long long elementsLessThan_X(long long x) {//return the number of eleemnts less than x in the multiset
		return s.order_of_key(x);
	}

	long long elementsGreaterThan_X(long long x) {//return the number of elements greater than x in the multiset
		return size()-elementsLessThan_X(x+1);
	}

	long long elementsGreaterOrEqual_X(long long x) {//return the elements greater than or equal to x in the multiset
		return size()-elementsLessThan_X(x);
	}

	long long elementsLessOrEqual_X(long long x) {//return the elements less than or equal to x in the multiset
		return size()-elementsGreaterThan_X(x);
	}

};
