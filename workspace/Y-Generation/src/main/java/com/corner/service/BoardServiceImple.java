package com.corner.service;

import java.util.List;

import org.springframework.stereotype.Service;

import com.corner.domain.BoardVO;
import com.corner.domain.Criteria;
import com.corner.mapper.BoardMapper;

import lombok.AllArgsConstructor;
import lombok.extern.log4j.Log4j;

@Service
@AllArgsConstructor
@Log4j
public class BoardServiceImple implements BoardService {
	
	private BoardMapper mapper;

	@Override
	public void register(BoardVO board) {
		mapper.insertSelectKey_bno(board);
	}

	@Override
	public BoardVO get(Long bno) {
		return mapper.read(bno);
	}

	@Override
	public int getTotal() {
		return mapper.getTotal();
	}
	@Override
	public int getTotal(Criteria cri) {
		return mapper.getTotal(cri);
	}

	@Override
	public boolean modify(BoardVO board) {
		return mapper.update(board) == 1;
	}

	@Override
	public boolean remove(Long bno) {
		return mapper.delete(bno) == 1;
	}

	@Override
	public List<BoardVO> getList() {
		log.info("getList...............");
		return mapper.getList();
	}
	@Override
	public List<BoardVO> getList(Criteria cri) {
		return mapper.getListWithPaging(cri);
	}

}
