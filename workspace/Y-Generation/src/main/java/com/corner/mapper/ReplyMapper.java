package com.corner.mapper;

import java.util.List;

import org.apache.ibatis.annotations.Param;

import com.corner.domain.Criteria;
import com.corner.domain.ReplyVO;

public interface ReplyMapper {
	public int insert(ReplyVO reply);
	public ReplyVO read(Long bno);
	public int delete(Long rno);
	public int update(ReplyVO reply);
	
	public List<ReplyVO> getListWithPaging(
			@Param("cri") Criteria cri,
			@Param("bno") Long bno);
	
	public int getTotal(Long bno);
}
