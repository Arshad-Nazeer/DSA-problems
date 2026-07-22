<h2><a href="https://leetcode.com/problems/find-greatest-common-divisor-of-array">2106. Find Greatest Common Divisor of Array</a></h2><h3>Easy</h3><hr><p>Given an integer array <code>nums</code>, return<strong> </strong><em>the <strong>greatest common divisor</strong> of the smallest number and largest number in </em><code>nums</code>.</p>

<p>The <strong>greatest common divisor</strong> of two numbers is the largest positive integer that evenly divides both numbers.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,5,6,9,10]
<strong>Output:</strong> 2
<strong>Explanation:</strong>
The smallest number in nums is 2.
The largest number in nums is 10.
The greatest common divisor of 2 and 10 is 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [7,5,6,8,3]
<strong>Output:</strong> 1
<strong>Explanation:</strong>
The smallest number in nums is 3.
The largest number in nums is 8.
The greatest common divisor of 3 and 8 is 1.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,3]
<strong>Output:</strong> 3
<strong>Explanation:</strong>
The smallest number in nums is 3.
The largest number in nums is 3.
The greatest common divisor of 3 and 3 is 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

Logic of Euclid's Algorithm:

If d divides both a and b (assume a > b), then d also divides their difference (a − b), since divisors are preserved under linear combinations. Therefore,

gcd(a, b) = gcd(a − b, b).

Repeating this process preserves the GCD while reducing the larger number. Instead of repeatedly subtracting b from a, we can subtract as many multiples of b as possible in one step using:

a % b = a − ⌊a/b⌋ · b.

Thus,

gcd(a, b) = gcd(b, a % b).

Eventually, the remainder becomes 0. At that point, the remaining non-zero number divides both itself and 0, so it is the greatest common divisor.
