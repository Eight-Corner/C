package com.corner.service;

import java.util.List;

import com.corner.domain.Criteria;
import com.corner.domain.ReplyPageDTO;
import com.corner.domain.ReplyVO;

public interface ReplyService {
	
	public int register(ReplyVO reply);
	public ReplyVO get(Long rno);
	public int modify(ReplyVO reply);
	public int remove(Long rno);
	
	public ReplyPageDTO getListWithPaging(Criteria cri, Long bno);
}
