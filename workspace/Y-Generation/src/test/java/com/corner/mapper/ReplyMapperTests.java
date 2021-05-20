package com.corner.mapper;

import java.util.stream.IntStream;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringRunner;

import com.corner.domain.BoardVO;
import com.corner.domain.Criteria;
import com.corner.domain.ReplyVO;

import lombok.Setter;
import lombok.extern.log4j.Log4j;

@RunWith(SpringRunner.class)
@ContextConfiguration("file:src/main/webapp/WEB-INF/spring/root-context.xml")
@Log4j
public class ReplyMapperTests {
	@Setter(onMethod_ = @Autowired)
	private ReplyMapper mapper;
	
	@Setter(onMethod_ = @Autowired)
	private BoardMapper board;

	private Long[] bnoArr = {7340032L, 7340031L, 7340030L, 7340029L, 7340028L};
	
//	@Test
//	public void testUpdate() {
//		Long rno = 3L;
//		ReplyVO reply = mapper.read(rno);
//		
//		reply.setReply("수정 댓글");
//		log.info("UPDATE COUNT: " + mapper.update(reply));
//	}
	
//	@Test
//	public void testDelete() {
//		Long rno = 2L;
//		log.info(mapper.delete(rno));
//	}
	
//	@Test
//	public void testGetListWithPaging() {
//		Criteria cri = new Criteria();
//		List<ReplyVO> replies = mapper.getListWithPaging(cri, bnoArr[0]);
//		replies.forEach(reply->log.info(reply));
////		mapper.getListWithPaging(bnoArr[0]).forEach(reply -> log.info(reply));
//	}
	
//	@Test
//	public void testRead() {
//		Long targetRno = 5L;
//		ReplyVO vo = mapper.read(targetRno);
//		log.info(vo);
//	}
	
//	@Before
//	@Test
//	public void testCreate() {
//		java.util.List<BoardVO> boards = board.getListWithPaging(new Criteria(1, 5));
//		IntStream.rangeClosed(1, 10).forEach(i -> {
//			ReplyVO reply = new ReplyVO();
//			reply.setReply("댓글 테스트 " + i);
//			reply.setReplyer("테드한 " + i);
//			// 0~n :  n+1로 나눈 나머지
//			reply.setBno(boards.get(i % 5 ).getBno());
////			reply.setBno(bnoArr[i%5]);
//			
//			mapper.insert(reply);
//			log.info(reply);
//		});
//	}
	
//	@Test
//	public void testMapper() {
//		log.info(mapper);
//	}
}
