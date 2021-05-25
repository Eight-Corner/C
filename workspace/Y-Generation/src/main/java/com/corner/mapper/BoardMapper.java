package com.corner.mapper;

import java.util.List;

import org.apache.ibatis.annotations.Param;

import com.corner.domain.BoardVO;
import com.corner.domain.Criteria;

public interface BoardMapper {
	
	public List<BoardVO> getList();
	public List<BoardVO> getListWithPaging(Criteria cri);
	
	public int getTotal();
	public int getTotal(Criteria cri);
	
	public void insert(BoardVO board);
	public void insertSelectKey_bno(BoardVO board);
	
	public BoardVO read(Long bno);
	
	public int delete(Long bno);
	
	public int update(BoardVO board);
	
	public void updateReplyCnt(@Param("bno") Long bno, @Param("amount") int amount);
	
}
