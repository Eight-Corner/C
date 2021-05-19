package com.corner.controller;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;
import org.springframework.test.context.web.WebAppConfiguration;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.request.MockMvcRequestBuilders;
import org.springframework.test.web.servlet.setup.MockMvcBuilders;
import org.springframework.web.context.WebApplicationContext;

import lombok.Setter;
import lombok.extern.log4j.Log4j;

@RunWith(SpringJUnit4ClassRunner.class)
@Log4j
@ContextConfiguration({
		"file:src/main/webapp/WEB-INF/spring/root-context.xml",
		"filefile:src/main/webapp/WEB-INF/spring/appServlet/servlet-context.xml"
})
@WebAppConfiguration
public class BoardControllerTests {
	@Setter(onMethod_ = @Autowired)
	
	private WebApplicationContext wac;
	private MockMvc mockMvc;
	
	@org.junit.Before
	public void setup() {
		this.mockMvc = MockMvcBuilders.webAppContextSetup(wac).build();
	}
	
	
	   
	
	
  @Test
  public void testGet() throws Exception {
	   log.info(mockMvc.perform(MockMvcRequestBuilders
			   .get("/board/read")
			   .param("bno", "8"))
			   .andReturn().getModelAndView().getModelMap()
			   );
  }
	
//  @Test
//  public void testList() throws Exception{
//     log.info(mockMvc.perform(MockMvcRequestBuilders.get("/board/list"))   // GET방식 URI 호출 
//              .andReturn()		// 응답된 결과값을 통해
//              .getModelAndView() // Model에 어떤 데이터가 담겨 있는지를 
//              .getModelMap());		// Map 형식으로 확인   
//     // model을 Map으로 바꿔준다.
//  }	

}
