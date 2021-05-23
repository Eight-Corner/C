package com.corner.domain;

import java.util.List;

import lombok.AllArgsConstructor;
import lombok.Data;

@Data
@AllArgsConstructor
public class ReplyPageDTO {
	private int replyCnt; // 해당 게시글의 총 댓글 수 
	private List<ReplyVO> list; // 해당 게시글에 페이지에 맞는 댓글 목록
}
