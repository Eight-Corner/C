package com.corner.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import com.corner.domain.MemberVO;
import com.corner.service.MemberService;

import lombok.AllArgsConstructor;

@Controller
@AllArgsConstructor
@RequestMapping("/account/*")
public class MemberController {
	
	private MemberService service;
	
	@GetMapping("/signup")
	public void register() {}
	
	@PostMapping("/signup")
	public String register(MemberVO member, RedirectAttributes rttr) {
		service.register(member);
		rttr.addFlashAttribute("result", member.getUsername());
		
		return "redirect:/";
	}
	
}
