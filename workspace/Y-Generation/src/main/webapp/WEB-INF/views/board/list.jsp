<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/functions" prefix="fn"%>
<!DOCTYPE html>
<html>
<head>
<title>자유게시판 | Y-Generation</title>
<meta charset="utf-8" />
<meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no" />
<link rel="stylesheet" href="/resources/assets/css/main.css" />
<link rel="shortcut icon" type="image/x-icon" href="/resources/images/y-title.png">
	<style>
	.big-width {display: block;	width: 100%;}
	.small-width {display: none;}
	.table-wrapper {overflow-x: hidden !important;}
	select {width: 25%;	display: inline;}
	input[name='keyword'] {	width: 54%; display: inline;}
	.search {	width: 20%;	margin-top: 5%; }
		@media ( max-width : 918px) {
			#searhForm { width: 100%;	}
			.writer { display: none;}
			.newDate {display: none;}
			.updateDate {display: none;	}
			.big-width {display: none;}
			.small-width {display: block;}
			.search {width: 100%;}
			select {width: 100%;}
			input[name='keyword'] {
				width: 100%;
				display: inline;
			}
		}
	.page {justify-content: center;}
	#pagination_prev {float: left;}
	#pagination_next {float: right}
	</style>
</head>
<body class="is-preload">

	<!-- Wrapper -->
	<div id="wrapper">

		<!-- Header -->
		<header id="header">

			<!-- Logo -->
			<div class="logo">
				<a href="/" class="title"><strong>개발자들의 모임</strong> <span
					class="extra">Hello World🤪</span></a>
			</div>

			<!-- Nav -->
			<nav id="nav">
				<ul>
					<li><a href="/">Home</a></li>
					<li><a href="#" class="dropdown">Dropdown</a>
						<ul>
							<li><a href="#">Lorem ipsum dolor</a></li>
							<li><a href="#">Magna phasellus</a></li>
							<li><a href="#">Etiam dolore nisl</a></li>
							<li><a href="#">서브 메뉴</a>
								<ul>
									<li><a href="#">Lorem ipsum dolor</a></li>
									<li><a href="#">Phasellus consequat</a></li>
									<li><a href="#">Magna phasellus</a></li>
									<li><a href="#">Etiam dolore nisl</a></li>
									<li><a href="#">Veroeros feugiat</a></li>
								</ul></li>
							<li><a href="#">Veroeros feugiat</a></li>
						</ul></li>
					<li><a href="/generic">공지사항</a></li>
					<li><a href="/board/list">자유게시판</a></li>
					<li><a href="/elements">Elements</a></li>
				</ul>
			</nav>

		</header>

		<!-- Main -->
		<div id="main">

			<!-- 검색바 -->
			<!-- Content -->
			<section class="main">
				<div class="inner">
					<c:forEach var="board" items="${list}" begin="0" end="0" varStatus="status">
						<header class="major">
							<span class="category">최신 글</span> <a href="/board/get?bno=${board.bno}&pageNum=${pageMaker.cri.pageNum}&amount=${pageMaker.cri.amount}">
								${board.bno} </a>
							<h2>
								<a href="/board/get?bno=${board.bno}&pageNum=${pageMaker.cri.pageNum}&amount=${pageMaker.cri.amount}">
								${board.title}</a>
							</h2>
							<ul class="meta">
								<li><c:set var="newDate1" value="${board.newDate}" /> 
									<c:set var="newDate2" value="${fn:substring(newDate1, 5, 10)}" />
									작성일 : ${newDate2}
								</li>
								<li><c:set var="updateDate1" value="${board.updateDate}" />
									<c:set var="updateDate2" value="${fn:substring(updateDate1, 5, 10)}" /> 
									수정일 : ${updateDate2}
								</li>
								<li><a href="#" class="favorites">2,174</a></li>
								<li><a href="#" class="comments">1,423</a></li>
							</ul>
						</header>
						<a href="/board/get?bno=${board.bno}&pageNum=${pageMaker.cri.pageNum}&amount=${pageMaker.cri.amount}" class="image main">
						<img src="/resources/images/bg/bg2.jpg" alt="" /></a>
							<c:set var="content1" value="${board.content}" />
							<c:set var="content2" value="${fn:substring(content1, 1, 30)}" />
							<p>${board.content} •••.</p>
					</c:forEach>
				</div>
			</section>

			<!-- Posts -->
			<section class="main">
				<div class="posts">
					<c:forEach var="board" items="${list}" begin="1" step="1">
						<article>
							<a href="#" class="image"><img src="/resources/images/bg/bg5.jpg" alt="" /></a>
							<header>
								<a href="/board/get?bno=${board.bno}&pageNum=${pageMaker.cri.pageNum}&amount=${pageMaker.cri.amount}">
									${board.bno}</a>
								<h2>
									<a href="/board/get?bno=${board.bno}&pageNum=${pageMaker.cri.pageNum}&amount=${pageMaker.cri.amount}">
									${board.title}</a>
								</h2>
								<ul class="meta">
									<li><c:set var="newDate1" value="${board.newDate}" /> <c:set var="newDate2" value="${fn:substring(newDate1, 5, 10)}" />
										작성일 : ${newDate2}
									</li>
									<li><c:set var="updateDate1" value="${board.updateDate}" />
										<c:set var="updateDate2" value="${fn:substring(updateDate1, 5, 10)}" /> 
										수정일 : ${updateDate2}</li>
									<li><a href="#" class="favorites">2,174</a></li>
									<li><a href="#" class="comments">1,423</a></li>
								</ul>
							</header>
							<p>
								<c:set var="content1" value="${board.content}" />
								<c:set var="content2" value="${fn:substring(content1, 1, 30)}" />
								${board.content} •••.
							</p>
							${board.writer}
							<footer>
								<ul class="actions">
									<li><a href="/board/get?bno=${board.bno}&pageNum=${pageMaker.cri.pageNum}&amount=${pageMaker.cri.amount}" class="button">Full Story</a></li>
								</ul>
							</footer>
						</article>

					</c:forEach>
				</div>
			<div style="margin: 0 auto; text-align: center;">
				<a href="/board/register${pageMaker.cri.getListLink()}" class="button small">글 등록</a>
			</div>
			<div class="big-width" style="text-align: center;">
				<footer class="major">
					<ul class="pagination" id="pagination_prev">
						<c:if test="${pageMaker.prev}">
							<li><a class="changePage" id="previous" href="${1}">&lt;&lt;First</a></li>
							<li><a class="changePage" id="previous" href="${pageMaker.startPage - 1}">&lt;PREV</a></li>
						</c:if>
					</ul>
					<ul class="pagination">
						<c:forEach var="num" begin="${pageMaker.startPage}" end="${pageMaker.endPage}">
							<c:choose>
								<c:when test="${num eq pageMaker.cri.pageNum}">
									<li><a class="page active">${num}</a></li>
								</c:when>
								<c:otherwise>
									<li><a class="changePage" id="page" href="${num}">${num}</a></li>
								</c:otherwise>
							</c:choose>
						</c:forEach>
					</ul>
					<ul class="pagination" id="pagination_next">
						<c:if test="${pageMaker.next}">
							<li><a class="changePage" id="next" href="${pageMaker.endPage + 1}">NEXT&gt;</a></li>
							<li><a class="changePage" id="next" href="${pageMaker.realEnd}">END&gt;&gt;</a></li>
						</c:if>
					</ul>
				</footer>
			</div>

			<div class="small-width" style="text-align: center;">
				<footer class="major">
					<ul class="pagination" id="pagination_prev">
						<c:if test="${pageMaker.cri.pageNum > 1}">
							<li><a id="previous" class="changePage" href="${1}">&lt;&lt;First</a></li>
							<li><a id="previous" class="changePage" href="${pageMaker.cri.pageNum - 1}">&lt;PREV</a></li>
						</c:if>
					</ul>
					<ul class="pagination">
						<li><a class="page active">${pageMaker.cri.pageNum}</a></li>
					</ul>
					<ul class="pagination" id="pagination_next">
						<c:if test="${pageMaker.cri.pageNum < pageMaker.realEnd}">
							<li><a class="changePage" id="next" href="${pageMaker.cri.pageNum + 1}">NEXT&gt;</a></li>
							<li><a class="changePage" id="next" href="${pageMaker.realEnd}">END&gt;&gt;</a></li>
						</c:if>
					</ul>
				</footer>
			</div>

			<form id="actionForm" action="/board/list">
				<input type="hidden" name="pageNum" value="${pageMaker.cri.pageNum}">
				<input type="hidden" name="amount" value="${pageMaker.cri.amount}">
				<input type="hidden" name="type" value="${pageMaker.cri.type}">
				<input type="hidden" name="keyword" value="${pageMaker.cri.keyword}">
			</form>
			<form action="/board/list" id="searchForm">
				<div class="fields">
					<div class="field">
						<div style="text-align: center">
							<select name="type">
								<option value="" ${pageMaker.cri.type == null ? 'selected':''}>검색 기준</option>
								<option value="T" ${pageMaker.cri.type == 'T' ? 'selected':''}>제목</option>
								<option value="C" ${pageMaker.cri.type == 'C' ? 'selected':''}>내용</option>
								<option value="W" ${pageMaker.cri.type == 'W' ? 'selected':''}>작성자</option>
								<option value="TC" ${pageMaker.cri.type == 'TC' ? 'selected':''}>제목 또는 내용</option>
								<option value="TW" ${pageMaker.cri.type == 'TW' ? 'selected':''}>제목 또는 작성자</option>
								<option value="TCW" ${pageMaker.cri.type == 'TCW' ? 'selected':''}>전체</option>
							</select> 
							<input id="keyword" type="text" name="keyword" value="${pageMaker.cri.keyword}"> 
							<a href="javascript:void(0)" class="search button primary icon solid fa-search">검색</a>
						</div>
					</div>
				</div>
			</form>
			</section>
		</div> <!-- main -->

		<!-- Footer -->
		<footer id="footer">
			<div class="inner">
				<section>
					<h2>Y-Generation</h2>
					<p>개발자 사이트의 블로그 입니다.</p>
					<ul class="icons style2">
						<li><a href="https://github.com/eight-corner" class="icon brands fa-github"> <span class="label">Github</span></a></li>
						<li><a href="#" class="icon brands fa-facebook-f"> <span class="label">Facebook</span></a></li>
						<li><a href="https://instagram.com" class="icon brands fa-instagram"> <span class="label">Instagram</span></a></li>
						<li><a href="https://youtube.com" class="icon brands fa-youtube"> <span class="label">YouTube</span></a></li>
					</ul>
				</section>
				<section>
					<h2>문의하기</h2>
					<form method="post" action="#">
						<div class="fields">
							<div class="field half">
								<input type="text" name="name" id="name" placeholder="Name" />
							</div>
							<div class="field half">
								<input type="email" name="email" id="email" placeholder="Email" />
							</div>
							<div class="field">
								<textarea name="message" id="message" placeholder="Message"
									rows="4"></textarea>
							</div>
						</div>
						<ul class="actions">
							<li><input type="submit" value="Send Message" /></li>
						</ul>
					</form>
				</section>
			</div>
			<div class="copyright">
				<p>&copy; 2021. Y-Generation Co. all rights reserved.</p>
			</div>
		</footer>

	</div> <!-- wrapper -->

	<!-- Scripts -->
	<script src="/resources/assets/js/jquery.min.js"></script>
	<script src="/resources/assets/js/jquery.dropotron.min.js"></script>
	<script src="/resources/assets/js/browser.min.js"></script>
	<script src="/resources/assets/js/breakpoints.min.js"></script>
	<script src="/resources/assets/js/util.js"></script>
	<script src="/resources/assets/js/main.js"></script>
</body>
<script>
	$("a.search").on("click", function(e) {
		e.preventDefault();
		var searchForm = $("#searchForm");

		if (!searchForm.find("option:selected").val()) {
			alert("검색 종류를 선택하세요.");
			return false;
		}
		if (!searchForm.find("input[name='keyword']").val()) {
			alert("키워드를 입력하세요.");
			return false;
		}
		searchForm.submit();
	})

		$(".changePage").on("click", function(e){
			e.preventDefault();
			var actionForm = $("#actionForm");
			var pageNum = $(this).attr("href");
			actionForm.find("input[name='pageNum']").val(pageNum);
			actionForm.submit();
		})

	//alert("${result}");
	var result = "${result}";
	$(document).ready(function() {
		if (result == '' || isNaN(result)) {
			return;
		}
		alert("게시글 " + result + "번이 등록되었습니다.")
	})
</script>
</html>