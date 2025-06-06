/*

For this exercise you will be strengthening your page-fu mastery. You will complete the
PaginationHelper class, which is a utility class helpful for querying paging information related to
an array.

The class is designed to take in an array of values and an integer indicating how many items will be
allowed per each page. The types of values contained within the collection/array are not relevant.

The following are some examples of how this class is used:


PaginationHelper<Character> helper = new PaginationHelper(Arrays.asList('a', 'b', 'c', 'd', 'e', 'f'), 4);
helper.pageCount(); //should == 2
helper.itemCount(); //should == 6
helper.pageItemCount(0); //should == 4
helper.pageItemCount(1); // last page - should == 2
helper.pageItemCount(2); // should == -1 since the page is invalid

// pageIndex takes an item index and returns the page that it belongs on
helper.pageIndex(5); //should == 1 (zero based index)
helper.pageIndex(2); //should == 0
helper.pageIndex(20); //should == -1
helper.pageIndex(-10); //should == -1

*/

package main

func main() {
	p := NewPagination([]int{'a', 'b', 'c', 'd', 'e', 'f'}, 4)

	assert(p.PageCount() == 2)
	assert(p.ItemCount() == 6)

	assert(p.PageItemCount(0) == 4)
	assert(p.PageItemCount(1) == 2)
	assert(p.PageItemCount(2) == -1)

	assert(p.PageIndex(2) == 0)
	assert(p.PageIndex(5) == 1)
	assert(p.PageIndex(-10) == -1)
	assert(p.PageIndex(20) == -1)

	p = NewPagination([]int{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'w', 'x', 'y'}, 10)
	assert(p.PageItemCount(2) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Pagination struct {
	listsize int
	pagesize int
}

func NewPagination[T any](collection []T, itemsperpage int) *Pagination {
	return &Pagination{
		listsize: len(collection),
		pagesize: itemsperpage,
	}
}

func (p *Pagination) ItemCount() int {
	return p.listsize
}

func (p *Pagination) PageCount() int {
	return p.ItemCount()/p.pagesize + 1
}

func (p *Pagination) PageItemCount(pageindex int) int {
	pagecount := p.PageCount()
	if pageindex >= pagecount {
		return -1
	}
	if pageindex < pagecount-1 {
		return p.pagesize
	}
	return p.ItemCount() - p.pagesize*pageindex
}

func (p *Pagination) PageIndex(itemindex int) int {
	if itemindex < 0 || itemindex >= p.ItemCount() {
		return -1
	}
	return itemindex / p.pagesize
}
