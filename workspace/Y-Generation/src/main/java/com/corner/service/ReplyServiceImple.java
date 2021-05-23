package com.corner.service;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.corner.domain.Criteria;
import com.corner.domain.ReplyPageDTO;
import com.corner.domain.ReplyVO;
import com.corner.mapper.ReplyMapper;

import lombok.AllArgsConstructor;
import lombok.Setter;
import lombok.extern.log4j.Log4j;

@Service
@Log4j
@AllArgsConstructor
public class ReplyServiceImple implements ReplyService {
	
	@Setter(onMethod_ = @Autowired)
	public ReplyMapper mapper;

	@Override
	public int register(ReplyVO reply) {
		return mapper.insert(reply);
	}

	@Override
	public ReplyVO get(Long rno) {
		return mapper.read(rno);
	}

	@Override
	public int modify(ReplyVO reply) {
		return mapper.update(reply);
	}

	@Override
	public int remove(Long rno) {
		return mapper.delete(rno);
	}

	@Override
	public ReplyPageDTO getListWithPaging(Criteria cri, Long bno) {
		log.info("get Reply List of a board " + bno);
		return new ReplyPageDTO(mapper.getTotal(bno), mapper.getListWithPaging(cri, bno));
	}

}
