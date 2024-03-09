# [Silver I] IOIOI - 5525 

[문제 링크](https://www.acmicpc.net/problem/5525) 

### 성능 요약

메모리: 4916 KB, 시간: 40 ms

### 분류

문자열

### 제출 일자

2024년 3월 10일 03:42:18

### 문제 설명

<p>N+1개의 <code>I</code>와 N개의 <code>O</code>로 이루어져 있으면, <code>I</code>와 <code>O</code>이 교대로 나오는 문자열을 P<sub>N</sub>이라고 한다.</p>

<ul>
	<li>P<sub>1</sub> <code>IOI</code></li>
	<li>P<sub>2</sub> <code>IOIOI</code></li>
	<li>P<sub>3</sub> <code>IOIOIOI</code></li>
	<li>P<sub>N</sub> <code>IOIOI...OI</code> (<code>O</code>가 N개)</li>
</ul>

<p><code>I</code>와 <code>O</code>로만 이루어진 문자열 S와 정수 N이 주어졌을 때, S안에 P<sub>N</sub>이 몇 군데 포함되어 있는지 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 N이 주어진다. 둘째 줄에는 S의 길이 M이 주어지며, 셋째 줄에 S가 주어진다.</p>

### 출력 

 <p>S에 P<sub>N</sub>이 몇 군데 포함되어 있는지 출력한다.</p>

 ### 풀이

 처음엔 패턴이 틀리기 시작한 인덱스로 탐색위치를 점프/패턴 일치 시 뒤에 이어 나오는 "OI"의 개수를 추가 카운팅하는 방식으로 접근, 시간초과\(패턴 문자열 제작 함수와 while 조건 비교 과정에서 시간이 오래 걸린 것으로 추정\). 이후 kmp 사용하였으나 또 시간초과.

 마지막으로 'I'다음에 위치한 "OI"문자열의 개수를 세어 n과 비교하는 방식으로 전환하여 시간 내 풀이 성공

