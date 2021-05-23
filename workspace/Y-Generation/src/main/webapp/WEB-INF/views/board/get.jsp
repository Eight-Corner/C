<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/functions" prefix="fn"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt"%>
<!DOCTYPE html>
<html>

   <head>
      <title>Off Topic | Y-Generation</title>
      <meta charset="utf-8" />
      <meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no" />
      <meta name="description" content="" />
      <meta name="keywords" content="" />
      <link rel="stylesheet" href="/resources/assets/css/main.css" />
      <style>
      	.line{border-bottom: 1px solid #dbdbdb;}
      	.date{font-size: 12px; top: -60px; position: relative;}
      </style>
   </head>
   <body class="is-preload">
   
      <!-- Main -->
            <div class="wrapper">
		         <div id="main">
   				<%@include file="../includes/header.jsp" %>
   				
				<section class="main">
	               <div class="inner">

	                  <!-- Elements -->
	                <header class="major">
	                   <h2>Board</h2>
	                   <p>게시글 등록</p>
	                </header>
	                    <h3><a href="/board/list${cri.getListLink()}" class="button small">목록 보기</a></h3>
	                  <div class="content">
	                     <div class="form">
	                        <form action="/board/remove">
	                           <div class="fields">
	                              <div class="field">
	                                 <h4>No.</h4>
	                                 <input name="bno" type="text" value="${board.bno}" readonly/>
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
	                              </div>
	                              <div class="field">
	                                 <h4>제목</h4>
	                                 <input name="title" type="text" value="${board.title}" readonly/>
	                              </div>
	                              <div class="field">
	                                 <h4>내용</h4>
	                                 <textarea name="content" rows="6" style="resize:none" readonly>${board.content}</textarea>
	                              </div>
	                              <div class="field">
	                                 <h4>작성자</h4>
	                                 <input name="writer" type="text" value="${board.writer}" readonly/>
	                              </div>
	                           </div>
	                           <ul class="actions special">
	                              <li>
	                                 <input type="button" class="button" value="수정" onclick="location.href='/board/modify${cri.getListLink()}&bno=${board.bno}'"/>
	                                 <input type="submit" class="button" value="삭제"/>
			                         <input type="hidden" name="pageNum" value="${cri.pageNum}">
			                         <input type="hidden" name="amount" value="${cri.amount}">
			                         <input type="hidden" name="type" value="${cri.type}">
			                         <input type="hidden" name="keyword" value="${cri.keyword}">
	                              </li>
	                           </ul>
	                           <ul class="icons">
		                           <li>
		                           		<span class="icon solid fa-envelope"></span>
		                           		<strong>댓글</strong>
		                           </li>
	                           </ul>
	                           <a style="width:100%;" href="javascript:void(0)" class="button primary small register">댓글 등록</a>
									<div class="fields register-form" style="display: none;">
										<div class="field">
			                           		<h4>닉네임</h4>
			                           		<input type="text" name="replyer" placeholder="Replyer">
	                           			</div>
	                           			<div class="field">
	                           				<h4>내용</h4>
	                           				<textarea rows="6" name="reply" placeholder="Reply" style="resize: none;"></textarea>
	                           			</div>
	                           			<div class="field regBtn">
	                           				<a href="javascript:void(0)" class="button primary small finish">등록</a>
	                           				<a href="javascript:void(0)" class="button primary small cancel">취소</a>
	                           			</div>
                           			</div>
								<ul class="replies">
								</ul>
								<div class="paging" style="text-align: center;">
									<ul class="pagination">
									
									</ul>
								</div>
                       		</form>
	                     </div>
	                   </div> <!-- div contents -->
            		</div> <!-- div inner --> 
				</section>
	         </div> <!-- div-wrapper  --> 
	      </div> <!--div main end -->
		<%@include file="../includes/footer.jsp" %>
		<script src="/resources/assets/js/reply.js"></script>
   </body>
<script>
	$(document).ready(function() {
		var bno = "${board.bno}";
		var pageNum = 1;
		
		showList();
		
		$(".register").on("click", function(e) {
			e.preventDefault();
			$(".register-form").show();
			$(this).hide();
		});
		
		$(".cancel").on("click", function(e) {
			e.preventDefault();
			$(".register-form").hide();
			$(".register").show();
		});
		
		$(".finish").on("click", function (e) {
			e.preventDefault();
			
			var reply = $("textarea[name='reply']").val();
			var replyer = $("input[name='replyer']").val();
			
			replyService.add({bno: bno, reply:reply, replyer:replyer},
				function(result) {
					alert(result);
					pageNum = 1;
					showList(pageNum);
				});
		});
	
		function showReplyPage(replyCnt) {
			var str = "";
			var replyPaging = $(".pagination");
            var endNum = Math.ceil(pageNum / 10.0) * 10;
            var startNum = endNum - 9;
            var realEnd = Math.ceil(replyCnt / 10.0);
			
			if(endNum > realEnd){
				endNum = realEnd;
			}
			
			var prev = startNum != 1;
			var next = endNum * 10 < replyCnt;
			
			if(matchMedia("screen and (max-width:918px)").matches){
				if(pageNum != 1) {
					str += "<li><a class='changePage' id='previous' href='"+ (pageNum - 1) +"'>&lt;</a></li>"
				}
					str += "<li><a class='page active'>"+ pageNum +"</a>"
				if(pageNum != realEnd) {
					str += "<li><a class='changePage' id='next' href='"+ (pageNum + 1) +"'>&gt;</a></li>"
				}
			} else {
				if(prev){
					str += "<li><a class='changePage' id='previous' href='"+ (startNum - 1) +"'>&lt;</a></li>"	
				}
				for(let i=startNum; i<=endNum; i++ ){
					if(pageNum == i) {
						str += "<li><a class='page active'>"+ i +"</a></li>";
						continue;
					}
					str += "<li><a class='changePage' id='page' href='"+ i +"'>"+ i +"</a></li>"
				}
				if(next) {
					str += "<li><a class='changePage' id='next' href='"+ (endNum + 1) +"'>&gt;</a></li>"
				}
			}
			replyPaging.html(str);
		}
		
		$(".pagination").on("click", "a.changePage", function(e) {
			e.preventDefault();
			pageNum = parseInt($(this).attr("href"));
			showList(pageNum);
		});
		
		   function showList(page){
	            var replyUL = $(".replies");
	            replyService.getList({bno:bno, page:page||1},
	                  function(replyCnt, list){//컨트롤러에서 응답한 댓글 전체 개수와 댓글 목록을 받는다.
	                     if(list == null || list.length == 0){
	                        //만약 현재 페이지가 1보다 클 때 더 이상 보여줄 댓글이 없다면
	                        //이전 페이지로 이동하여 댓글 목록을 보여주도록 한다.
	                        if(pageNum > 1){pageNum -= 1; showList(pageNum);}   
	                        replyUL.html("등록된 댓글이 없습니다.");
	                        return;
	                     }
	                     var str = "";
	                     //data 속성
	                     //태그에 원하는 value를 저장시키기 위해서 사용한다.
	                     //data-변수명="value"로 작성하며, jQuery에서 해당 태그객체.data("변수명")으로
	                     //value를 가져와 사용할 수 있다.
	                     //만약 value를 수정하고 싶다면 해당 태그객체.data("변수명","새로운 값");
	                     for(let i=0, len=list.length; i<len; i++){
                    	 	var rDate = list[i].replyDate.substr(0,16);
                    	 	var uDate = list[i].updateDate.substr(0,16);
	                        str += "<li data-rno='" + list[i].rno + "'>";
	                        str += "<strong>" + list[i].replyer + "</strong>";
	                        str += "<p class='reply" + list[i].rno + "'>" + list[i].reply + "</p>";
	                        str += "<div style='text-align:right;'>";
	                        str += "<span class='date'><img src='/resources/images/value_date_icon.png' height='13px;' weight='13px'>";
	                        str += "작성일: "+ rDate + " | 수정일: "+ uDate +"</span>";
	                        str += "<a class='modify' href='" + list[i].rno + "'>수정</a>"
	                        str += "<a class='finish' href='" + list[i].rno + "' style='display:none;'>수정완료</a>"
	                        str += "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
	                        str += "<a class='remove' href='" + list[i].rno + "'>삭제</a>"
	                        str += "</div><div class='line'></div></li>";
	                     }
	                     replyUL.html(str);
	                     showReplyPage(replyCnt);
	            });
	         }
		
		$(".replies").on("click", "a.remove", function(e) {
			e.preventDefault();
			var rnoValue = $(this).attr("href");
			
			replyService.remove(rnoValue, function(result) {
				alert(result);
				showList(pageNum);
			});
		});
		
		var check = false;
		
		$(".replies").on("click", "a.modify", function(e) {
			e.preventDefault();
			if(check){
				alert("이미 수정중인 댓글이 있습니다.");
				return;
			}
			var rnoValue = $(this).attr("href");
			var replyTag = $(".reply"+ rnoValue);
			
			replyTag.html("<textarea class='"+ rnoValue + "'>" + replyTag.text() + "</textarea>")
			$(this).hide();
			
			var finishs = $(".finish")
			for(let i = 0; i<finishs.length; i++ ){
				if($(finishs[i]).attr("href") == rnoValue){
					$(finishs[i]).show();
					check = true;
					break;
				}
			}
		});
				
			$(".replies").on("click", "a.finish", function(e) {
				e.preventDefault();
				var rnoValue = $(this).attr("href");
				var newReply = $("."+rnoValue).val();
				replyService.modify({rno: rnoValue, reply: newReply}, function(result) {
					alert(result);
					check = true;
					showList(pageNum);
				});
			});
		});
</script>
</html>
