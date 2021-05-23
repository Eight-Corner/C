/**
 * Javascript의 모듈화
 * 	함수들을 하나의 모듈처럼 묶음으로 구성하는 것을 의미한다.
 * 	화면 내에서 Javascript 처리를 하다 보면 이벤트 처리와 DOM, Ajax 처리 등
 * 	복잡하게 섞여서 유지보수가 힘들다. 따라서 Javascript를 하나의 모듈처럼 구성하여
 * 	사용한다.
 */

console.log("Reply Module.........");

var replyService = (function(){
	
	function add(reply, callback, error){
		console.log("add reply..........");
		$.ajax({
			type: "post",
			url: "/replies/new",
			data: JSON.stringify(reply),
			contentType: "application/json; charset=utf-8",
			success: function(result){
				if(callback){
					callback(result);
				}
			},
			error: function(xhr, status, er){
				if(error){
					error(er);
				}
			}
		});
	}
	
	function getList(param, callback, error){
		var bno = param.bno;
		var page = param.page || 1;
		$.getJSON("/replies/pages/" + bno + "/" + page + ".json", 
				function(data){
				//getList 컨트롤러에서는 댓글 목록과 댓글 전체 개수를 응답해준다.
				//따로 전달받지 않고 ReplyPageDTO객체로 한 번에 전달 받는다.
					if(callback){callback(data.replyCnt, data.list);}//callback함수에 전체개수와 목록을 따로 전달해준다.
		}).fail(function(xhr, status, err){
					if(error){error(err);}
		});
	}
	
	//댓글 삭제
	function remove(rno, callback, error){
		$.ajax({
			type:"delete",
			url:"/replies/" + rno,
			success:function(result){
				if(callback){
					callback(result);
				}
			},
			error:function(xhr, status, err){
				if(error){
					error(err);
				}
			}
		});
	}
	
	function modify(reply, callback, error){
		console.log("RNO : " + reply.rno);
		
		$.ajax({
			type: "put",
			url: "/replies/" + reply.rno,
			data: JSON.stringify(reply),
			contentType: "application/json; charset=utf-8",
			success:function(result){
				/*console.log("UPDATE : " + result);*/
				if(callback){callback(result);}
			},
			error: function(xhr, status, err){
				/*console.log("ERROR");*/
				if(error){error(err);}
			}
		});
	}
	
	function get(rno, callback, error){
		$.get("/replies/" + rno + ".json", function(result){
			if(callback){callback(result);}
		}).fail(function(xhr, status, err){
			if(error){
				error(err);
			}
		})
	}
	
	/*return {name : "AAAA"};*/
	return {add : add, getList : getList, remove : remove, modify : modify, get : get}
})();
