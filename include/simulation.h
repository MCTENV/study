#pragma once

/**
 * @brief 雾仿真函数
 * @param  visibility       大气能见度
 * @param  radius           激光雷达扫描半径
 * @return float 激光衰减值
 */
float Fog(float visibility, float radius);

