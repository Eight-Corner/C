package com.corner.mapper;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringRunner;

import com.corner.domain.MemberVO;

import lombok.Setter;
import lombok.extern.log4j.Log4j;

@RunWith(SpringRunner.class)
@ContextConfiguration("file:src/main/webapp/WEB-INF/spring/root-context.xml")
@Log4j
public class MemberMapperTests {
	
	@Setter(onMethod_ = @Autowired)
	private MemberMapper member;
	
	
	
//	@Test
//	public void testRegister() {
//		MemberVO vo = new MemberVO();
//		vo.setUsername("test2");
//		vo.setPassword("test1");
//		vo.setEmailAddress("eventmoa1515@gmail.com");
//		member.register(vo);
//		log.info(member);
//	}
	
//	@Test
//	public void testMapper() {
//		log.info(member);
//	}
}
