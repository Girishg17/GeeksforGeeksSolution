<h2><a href="https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1?page=2&sprint=ca8ae412173dbd8346c26a0295d098fd&sortBy=submissions">Maximum Rectangular Area in a Histogram</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is<strong> 1 unit</strong>, there will be <strong>N</strong> bars height of each bar will be given by the array <strong>arr</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>N = 7
arr[] = {6,2,5,4,5,1,6</span><span style="font-size: 18px;">}
<strong>Output: </strong>12<strong>
Explanation:</strong> In this example the largest area would be 12 of height 4 and width 3. We can achieve this <br>area by choosing 3rd, 4th and 5th bars.
</span><img src="http://d1hyf4ir1gqw6c.cloudfront.net/wp-content/uploads/histogram1.png" alt="">

</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>N = 8
arr[] = {7 2 8 9 1 3 6 5</span><span style="font-size: 18px;">}
<strong>Output: </strong>16<strong>
Explanation: </strong>Maximum size of the histogram 
will be 8&nbsp; and there will be 2 consecutive 
histogram. And hence the area of the 
histogram will be 8x2 = 16.</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>The task is to complete the function&nbsp;<strong>getMaxArea</strong>() which takes the array arr[] and its size N as inputs and&nbsp;finds the largest rectangular area possible and <strong>returns</strong> the answer.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complxity</strong> : O(N)<br><strong>Expected Auxilliary Space</strong> : O(N)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ N ≤ 10<sup>6</sup><br>0 ≤ arr[i] ≤ 10<sup>12</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Microsoft</code>&nbsp;<code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Stack</code>&nbsp;<code>Data Structures</code>&nbsp;