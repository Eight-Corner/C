package com.corner.service;

import com.corner.domain.MemberVO;

public interface MemberService {
	
	public void register(MemberVO vo);
	public MemberVO login(MemberVO vo) throws Exception;
}
