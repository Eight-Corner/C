package com.corner.mapper;

import com.corner.domain.MemberVO;

public interface MemberMapper {
	public void register(MemberVO member);
	public MemberVO login(MemberVO member);
}
