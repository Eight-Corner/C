package com.corner.controller;

import javax.servlet.http.HttpSession;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import com.corner.domain.MemberVO;
import com.corner.service.MemberService;

import lombok.AllArgsConstructor;

@Controller
@AllArgsConstructor
@RequestMapping("/account/*")
public class MemberController {
	
	private MemberService service;
	
	@GetMapping({"/signup", "/signin"})
	public void register() {}
	
	@PostMapping("/signup")
	public String register(MemberVO member, RedirectAttributes rttr) {
		service.register(member);
		rttr.addFlashAttribute("result", member.getUsername());
		
		return "redirect:/";
	}
	
	
	@RequestMapping(value = "/signin", method = RequestMethod.POST)
	public String login(MemberVO member, Model model, HttpSession session) { 
		
		MemberVO result = new MemberVO();
		try {
			result = service.login(member);
			if(result == null ) {
				model.addAttribute("message", "ID나 PW가 틀립니다.");
				return "login";
			} else {
				session.setAttribute("loginId", result.getUsername());
				return "/";
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		return "redirect:/";
	}
	
	
}
