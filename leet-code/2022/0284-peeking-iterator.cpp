// https://leetcode.com/problems/peeking-iterator/
// Medium

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
    using Type = int; // define Type here for the follow-up
public:
	PeekingIterator(const vector<Type>& nums) : Iterator(nums) {
	    next();
	}

	Type peek() {
        return next_item;
	}

	Type next() {
        Type tmp = std::move(next_item); // move just in case we use complex types (eg: strings)
        has_next_item = Iterator::hasNext();
	    if (has_next_item) {
            next_item = Iterator::next();
        }
        return tmp;
	}

	bool hasNext() const {
	    return has_next_item;
	}

private:
    bool has_next_item = false;
    Type next_item;
};
