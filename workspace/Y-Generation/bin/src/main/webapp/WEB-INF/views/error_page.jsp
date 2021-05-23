<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<!DOCTYPE html>
<html>
<head>
      <meta charset="utf-8" />
      <meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no" />
      <meta name="description" content="" />
      <meta name="keywords" content="" />
      <link rel="stylesheet" href="/resources/assets/css/main.css" />
      <link rel="stylesheet" href="/resources/assets/css/error.css" />
 	  <meta http-equiv="X-UA-Compatible" content="IE=edge">
   <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->

   <title>Error</title>

   <!-- Google font -->
   <link href="https://fonts.googleapis.com/css?family=Montserrat:200,400,700" rel="stylesheet">
</head>
<body class="is-preload">
	<!-- Wrapper -->
	<div id="wrapper">
		<!-- Main -->
		<div id="main">
			<%@include file="includes/header.jsp" %>
			<section class="main">
				<div>
				    <div class="wrapper style2 special" style="margin: 20% 0; text-align: center;">
				        <div class="inner" style="margin: 0 auto;">
				            <header class="major">
								<h2>NO PAGE!</h2>
							</header>
				            <hr class="major">
				            <h2 id="content">죄송합니다.</h2>
				            <p> 방문하시려는 페이지의 주소가 잘못 입력되었거나,
				                <br>페이지의 주소가 변경 혹은 삭제되어
				                <br>요청하신 페이지를 찾을 수 없습니다.</p>
				            <a href="/" class="button primary">메인<span class="arrow-right"></span>
				            </a>
				            <!-- <button type="submit">메인</button> -->
				        </div>
				    </div>
			    </div>
			</section>
		</div>
	</div>
	<%@include file="includes/footer.jsp" %>
</body>
</html>