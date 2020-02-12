import error_detection as edm

edm.introduce_error('sender_data.txt','sender_data_error.txt')
edm.make_frame('sender_data_error.txt','sender_frame.txt')

edm.vrc_frame('sender_frame.txt','vrc_frame.txt')
edm.introduce_error('vrc_frame.txt','vrc_received_frame.txt',0)
edm.chk_vrc_frame('vrc_received_frame.txt','vrc_frame_chk.txt')

edm.lrc_frame('sender_frame.txt','lrc_frame.txt')
edm.introduce_error('lrc_frame.txt','lrc_received_frame.txt',0)
edm.chk_lrc_frame('lrc_received_frame.txt','lrc_frame_chk.txt')

edm.checksum_frame('sender_frame.txt','checksum_frame.txt')
edm.introduce_error('checksum_frame.txt','checksum_received_frame.txt',0)
edm.chk_checksum_frame('checksum_received_frame.txt','checksum_frame_chk.txt')

edm.crc_frame('sender_frame.txt','crc_frame.txt')
edm.introduce_error('crc_frame.txt','crc_received_frame.txt',0)
edm.chk_crc_frame('crc_received_frame.txt','crc_frame_chk.txt')