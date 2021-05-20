/**
 * Javascript의 모듈화 

함수들을 하나의 모듈처럼 묶음으로 구성하는것을 의미한다.
화면 내에서 Javascript 처리를 하다 보면 이벤트 처리와 DOM, Ajax 처리 등 
복잡하게 섞여서 유지보수가 힘들다. 따라서 Javascript를 하나의 모듈처럼 구성하여 
사용한다.
 */

console.log("reply Module....");

var replyService = (function(){
	
	
	function add(reply, callback, error) {
		console.log("add reply.........");
		
		$.ajax({
			type: 'post',
			url: '/replies/new',
			data : JSON.stringify(reply),
			contentType : 'application/json; charset=utf-8',
			success: function(result, status, xhr) {
				if(callback){
					callback(result);
				}
			},
			error : function(xhr, status, er) {
				if(error) {
					error(er);
				}
			}
		})	
	}
	return {add : add};
	//return {name : "AAAA"}; 
	
})();
