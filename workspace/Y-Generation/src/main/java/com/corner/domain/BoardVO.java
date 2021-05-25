package com.corner.domain;

import lombok.Data;

@Data
public class BoardVO {
	private Long bno;
	private String title;
	private String content;
	private String writer;
	private String newDate;
	private String updateDate;
	private int replyCnt;
}
