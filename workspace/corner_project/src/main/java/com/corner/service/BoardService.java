package com.corner.service;

import java.util.List;

import com.corner.domain.BoardVO;
import com.corner.domain.Criteria;

public interface BoardService {
	
	public void register(BoardVO board);
	
	public BoardVO get(Long bno);
	
	public int getTotal(Criteria cri);
	
	public boolean modify(BoardVO board);
	
	public boolean remove(Long bno);
	
	public List<BoardVO> getList(Criteria cri);

}
