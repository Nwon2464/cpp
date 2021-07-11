problem C
Stable Groups

suppose you have 1 and 5
no two neighboring elements differ by more than x, which means
1 , 5 , they differ by 4, so if given x is 3, it is okay to
insert like 1 4 5 so they differ by 3 1

it turns out that in sorted array, the formula is
(A[i+1] - A[i] - 1) / X

K= 2 , X = 3
i.e [ 1  1  5  8  12  13  20  22]
        0  4  3  4   1   7   2  differences between two neighboors
if you are limted to insert element which is K operation is 2,
then you can pick any elements that differ by more than X
you can pick first 4 and second 4 which are both greater than
X.
suppose [1 , 5]
X = 3, you can insert only one element  A[i+1] - A[i] - 1 / X
										why - 1 ?
why -1 ? think of the case where X = 4, in array [1, 5]
5-1/X which is 1 which means that you can insert it but actually you cant
because they are already differ by X that's why you have to do - 1

lastly, it can be negative value as you divide such as 0 / 1 - 1 = -1
so you should do max at least 0, max(0LL, A[i+1]-A[i]-1/X)




