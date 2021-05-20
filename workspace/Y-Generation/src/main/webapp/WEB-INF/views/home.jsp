<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/functions" prefix="fn"%>
<!DOCTYPE HTML>
<!--
      
-->
<html>
	<head>
		<title>Y-Generation</title>
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
				@media ( max-width : 736px) {
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
			@media screen and (max-width: 480px) {
				a.button.small {
					width: 100%;
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

			<%@include file="includes/header.jsp" %>

				<!-- Banner -->
				<section id="banner">

					<!-- One -->
						<article class="full">
							<img src="/resources/images/bg/bg1.jpg" alt="" data-position="center" />
							<div class="content">
								<h2><a href="#">Hello World </a></h2>
								<p> 
									Hello World. 
								</p>
								<ul class="actions special">
									<li><a href="#" class="button">Full Story</a></li>
								</ul>
							</div>
						</article>

					<!-- Two -->
						<article class="half">
							<img src="/resources/images/bg/bg2.jpg" alt="" data-position="center" />
							<div class="content">
								<h2><a href="#">Aliquam veroeros</a></h2>
								<p>Dolor sit amet tempus adipiscing amet sed aliquam feugiat veroeros lorem ipsum dolor sit amet consequat.</p>
								<ul class="actions special">
									<li><a href="#" class="button">Full Story</a></li>
								</ul>
							</div>
						</article>

					<!-- Three -->
						<article class="half">
							<img src="/resources/images/bg/bg3.jpg" alt="" data-position="center" />
							<div class="content">
								<h2><a href="#">Tempus sed magna</a></h2>
								<p>Dolor sit amet tempus adipiscing amet sed aliquam feugiat veroeros lorem ipsum dolor sit amet consequat.</p>
								<ul class="actions special">
									<li><a href="#" class="button">Full Story</a></li>
								</ul>
							</div>
						</article>

				</section>

			<!-- Main -->
				<div id="main">

					<!-- Post -->
						<section class="main special">
							<div class="inner">
							<c:forEach var="board" items="${list}" begin="0" end="0" varStatus="status">
								<header class="major">
									<span class="category">최신 글</span> <a href="/board/get?bno=${board.bno}&pageNum=${pageMaker.cri.pageNum}&amount=${pageMaker.cri.amount}">
										No.${board.bno} </a>
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
									<footer>
											<ul class="actions special">
												<li><a href="/board/get?bno=${board.bno}&pageNum=${pageMaker.cri.pageNum}&amount=${pageMaker.cri.amount}" class="button">Full Story</a></li>
											</ul>
									</footer>
							</c:forEach>
							</div>
						</section>

					<!-- Posts -->
						<section class="main">
							<div class="posts">
							<c:forEach var="board" items="${list}" begin="1" step="1">
								<article>
									<a href="/board/get?bno=${board.bno}&pageNum=${pageMaker.cri.pageNum}&amount=${pageMaker.cri.amount}" class="image"><img src="/resources/images/bg/bg5.jpg" alt="" /></a>
									<header>
										<a href="/board/get?bno=${board.bno}&pageNum=${pageMaker.cri.pageNum}&amount=${pageMaker.cri.amount}">
											No.${board.bno}</a>
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
												수정일 : ${updateDate2}
											</li>
										</ul>
										<ul class="meta">
											<li><a href="#" class="favorites">2,174</a></li>
											<li><a href="#" class="comments">1,423</a></li>
										</ul>
									</header>
									<p>
										<c:set var="content1" value="${board.content}" />
										<c:set var="content2" value="${fn:substring(content1, 1, 30)}" />
										${board.content} •••.
									</p>
									작성자 : ${board.writer}
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
								<li><span class="extra">&hellip;</span></li>
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
				</div>

	</div>
<%@include file="includes/footer.jsp" %>
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