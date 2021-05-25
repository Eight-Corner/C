package com.corner.controller;

import javax.inject.Inject;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;

import com.corner.domain.EmailDTO;
import com.corner.service.EmailService;

@Controller
@RequestMapping("email/*")
public class EmailController {

	@Inject
	EmailService emailService; 
	
	@RequestMapping("send")
	public String send(@ModelAttribute EmailDTO dto, Model model) {
		try {
			emailService.sendMail(dto);// dto 메일 관련 정보를 sendMail에 저장한다.
			model.addAttribute("message", "이메일이 발송되었습니다..");
		} catch (Exception e) {
			e.printStackTrace();
			model.addAttribute("message", "이메일 발송 실패 ..");
		} 
		return "/account/login";
	}
	
}
