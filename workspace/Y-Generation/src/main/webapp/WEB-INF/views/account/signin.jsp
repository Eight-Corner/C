<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/functions" prefix="fn"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Y-Generation</title>
	<meta charset="utf-8" />
	<meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no" />
	<link rel="stylesheet" href="/resources/assets/css/main.css" />
	<link rel="shortcut icon" type="image/x-icon" href="/resources/images/y-title.png">
	
</head>
<body class="is-preload">

<!-- Wrapper -->
<div id="wrapper">
	<%@include file="../includes/header.jsp" %>



	
<form name="loginForm" action="${pageContext.request.contextPath}/user/UserLoginOk.us" method="post">
	<div class="row gtr-uniform" id="loginFrame">
		<div class="col-12">
				<label for="user_Id">아이디</label> 
				<input type="text" name="user_Id" id="user_Id" onkeyup="enterkey();"/>
				
				<label for="user_Pw">비밀번호</label> 
				<input type="password" name="user_Pw" id="user_Pw" onkeyup="enterkey();"/>
					
				<p class="signup-forgotten">
					<a href="/account/signup" class="sign-up" style="font-weight: bold;">회원가입</a>
					<span></span>
					<a href="#" class="forgotten">아이디/비밀번호 찾기</a>
				</p>
				
			<div class="col-6 col-12-medium">
				<ul class="actions stacked">
					<li>
					  <a href="javascript:loginCheck()" class="button primary fit">로그인</a>
					</li>
				</ul>
			</div>
		</div>
		
	</div>
</form>



</div>
<%@include file="../includes/footer.jsp" %>

</body>
	<script>
	var form = document.loginForm;
	
	function loginCheck(){
		
	    if(!form.user_Id.value){
	        alert("아이디를 입력해주세요.");
	        form.user_Id.focus();
	        return;
	    } 
	    else if(!form.user_Pw.value){
	        alert("비밀번호를 입력해주세요.");
	        form.user_Pw.focus();
	        return;
	    } 
	    
		form.submit();
	    
	}
	
	function enterkey() {
        if (window.event.keyCode == 13) {
             loginCheck();
        }
    }
	
	function logout() {
		location.href = "/account/logout";
		alert('로그아웃 되셨습니다. 감사합니다.');
	}
	</script>

</html>