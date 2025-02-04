/*
;    Project:       Open Vehicle Monitor System
;    Date:          14th March 2017
;
;    Changes:
;    1.0  Initial release
;
;    (C) 2011       Michael Stegen / Stegen Electronics
;    (C) 2011-2017  Mark Webb-Johnson
;    (C) 2011        Sonny Chen @ EPRO/DX
;
; Permission is hereby granted, free of charge, to any person obtaining a copy
; of this software and associated documentation files (the "Software"), to deal
; in the Software without restriction, including without limitation the rights
; to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
; copies of the Software, and to permit persons to whom the Software is
; furnished to do so, subject to the following conditions:
;
; The above copyright notice and this permission notice shall be included in
; all copies or substantial portions of the Software.
;
; THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
; IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
; FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
; AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
; LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
; OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
; THE SOFTWARE.
*/

#include "metrics_standard.h"

MetricsStandard StandardMetrics __attribute__ ((init_priority (1810)));

MetricsStandard::MetricsStandard()
  {
  ms_m_version = new OvmsMetricString(MS_M_VERSION);
  ms_m_hardware = new OvmsMetricString(MS_M_HARDWARE);
  ms_m_serial = new OvmsMetricString(MS_M_SERIAL);
  ms_m_tasks = new OvmsMetricInt(MS_M_TASKS, SM_STALE_MID);
  ms_m_freeram = new OvmsMetricInt(MS_M_FREERAM, SM_STALE_MID);
  ms_m_monotonic = new OvmsMetricInt(MS_M_MONOTONIC, SM_STALE_MIN, Seconds);
  ms_m_timeutc = new OvmsMetricInt(MS_M_TIME_UTC, SM_STALE_MIN, Seconds);

  ms_m_net_type = new OvmsMetricString(MS_N_TYPE, SM_STALE_MAX);
  ms_m_net_sq = new OvmsMetricInt(MS_N_SQ, SM_STALE_MAX, dbm);
  ms_m_net_provider = new OvmsMetricString(MS_N_PROVIDER, SM_STALE_MAX);
  ms_m_net_mdm_iccid = new OvmsMetricString(MS_N_MDM_ICCID, SM_STALE_MAX);
  ms_m_net_mdm_model = new OvmsMetricString(MS_N_MDM_MODEL, SM_STALE_MAX);

  ms_s_v2_connected = new OvmsMetricBool(MS_S_V2_CONNECTED);
  ms_s_v2_peers = new OvmsMetricInt(MS_S_V2_PEERS);

  ms_s_v3_connected = new OvmsMetricBool(MS_S_V3_CONNECTED);
  ms_s_v3_peers = new OvmsMetricInt(MS_S_V3_PEERS);

  ms_v_type = new OvmsMetricString(MS_V_TYPE);
  ms_v_vin = new OvmsMetricString(MS_V_VIN);

  ms_v_bat_soc = new OvmsMetricFloat(MS_V_BAT_SOC, SM_STALE_HIGH, Percentage);
  ms_v_bat_soh = new OvmsMetricFloat(MS_V_BAT_SOH, SM_STALE_HIGH, Percentage);
  ms_v_bat_cac = new OvmsMetricFloat(MS_V_BAT_CAC, SM_STALE_HIGH, AmpHours);
  ms_v_bat_health = new OvmsMetricString(MS_V_BAT_HEALTH, SM_STALE_HIGH);
  ms_v_bat_voltage = new OvmsMetricFloat(MS_V_BAT_VOLTAGE, SM_STALE_MID, Volts);
  ms_v_bat_current = new OvmsMetricFloat(MS_V_BAT_CURRENT, SM_STALE_MID, Amps);
  ms_v_bat_coulomb_used = new OvmsMetricFloat(MS_V_BAT_COULOMB_USED, SM_STALE_MID, AmpHours);
  ms_v_bat_coulomb_recd = new OvmsMetricFloat(MS_V_BAT_COULOMB_RECD, SM_STALE_MID, AmpHours);
  ms_v_bat_power = new OvmsMetricFloat(MS_V_BAT_POWER, SM_STALE_MID, kW);
  ms_v_bat_consumption = new OvmsMetricFloat(MS_V_BAT_CONSUMPTION, SM_STALE_MID, WattHoursPK);
  ms_v_bat_energy_used = new OvmsMetricFloat(MS_V_BAT_ENERGY_USED, SM_STALE_MID, kWh);
  ms_v_bat_energy_recd = new OvmsMetricFloat(MS_V_BAT_ENERGY_RECD, SM_STALE_MID, kWh);
  ms_v_bat_range_full = new OvmsMetricFloat(MS_V_BAT_RANGE_FULL, SM_STALE_HIGH, Kilometers);
  ms_v_bat_range_ideal = new OvmsMetricFloat(MS_V_BAT_RANGE_IDEAL, SM_STALE_HIGH, Kilometers);
  ms_v_bat_range_est = new OvmsMetricFloat(MS_V_BAT_RANGE_EST, SM_STALE_HIGH, Kilometers);
  ms_v_bat_12v_voltage = new OvmsMetricFloat(MS_V_BAT_12V_VOLTAGE, SM_STALE_HIGH, Volts);
  ms_v_bat_12v_current = new OvmsMetricFloat(MS_V_BAT_12V_CURRENT, SM_STALE_HIGH, Amps);
  ms_v_bat_12v_voltage_ref = new OvmsMetricFloat(MS_V_BAT_12V_VOLTAGE_REF, SM_STALE_HIGH, Volts);
  ms_v_bat_12v_voltage_alert = new OvmsMetricBool(MS_V_BAT_12V_VOLTAGE_ALERT, SM_STALE_MID);
  
  ms_v_bat_pack_level_min = new OvmsMetricFloat(MS_V_BAT_PACK_LEVEL_MIN, SM_STALE_HIGH, Percentage);
  ms_v_bat_pack_level_max = new OvmsMetricFloat(MS_V_BAT_PACK_LEVEL_MAX, SM_STALE_HIGH, Percentage);
  ms_v_bat_pack_level_avg = new OvmsMetricFloat(MS_V_BAT_PACK_LEVEL_AVG, SM_STALE_HIGH, Percentage);
  ms_v_bat_pack_level_stddev = new OvmsMetricFloat(MS_V_BAT_PACK_LEVEL_STDDEV, SM_STALE_HIGH, Percentage);
  
  ms_v_bat_pack_vmin = new OvmsMetricFloat(MS_V_BAT_PACK_VMIN, SM_STALE_HIGH, Volts);
  ms_v_bat_pack_vmax = new OvmsMetricFloat(MS_V_BAT_PACK_VMAX, SM_STALE_HIGH, Volts);
  ms_v_bat_pack_vavg = new OvmsMetricFloat(MS_V_BAT_PACK_VAVG, SM_STALE_HIGH, Volts);
  ms_v_bat_pack_vstddev = new OvmsMetricFloat(MS_V_BAT_PACK_VSTDDEV, SM_STALE_HIGH, Volts);
  ms_v_bat_pack_vstddev_max = new OvmsMetricFloat(MS_V_BAT_PACK_VSTDDEVMAX, SM_STALE_HIGH, Volts);

  ms_v_bat_pack_tmin = new OvmsMetricFloat(MS_V_BAT_PACK_TMIN, SM_STALE_HIGH, Celcius);
  ms_v_bat_pack_tmax = new OvmsMetricFloat(MS_V_BAT_PACK_TMAX, SM_STALE_HIGH, Celcius);
  ms_v_bat_pack_tavg = new OvmsMetricFloat(MS_V_BAT_PACK_TAVG, SM_STALE_HIGH, Celcius);
  ms_v_bat_pack_tstddev = new OvmsMetricFloat(MS_V_BAT_PACK_TSTDDEV, SM_STALE_HIGH, Celcius);
  ms_v_bat_pack_tstddev_max = new OvmsMetricFloat(MS_V_BAT_PACK_TSTDDEVMAX, SM_STALE_HIGH, Celcius);

  ms_v_bat_cell_voltage = new OvmsMetricVector<float>(MS_V_BAT_CELL_VOLTAGE, SM_STALE_HIGH, Volts);
  ms_v_bat_cell_vmin = new OvmsMetricVector<float>(MS_V_BAT_CELL_VMIN, SM_STALE_HIGH, Volts);
  ms_v_bat_cell_vmax = new OvmsMetricVector<float>(MS_V_BAT_CELL_VMAX, SM_STALE_HIGH, Volts);
  ms_v_bat_cell_vdevmax = new OvmsMetricVector<float>(MS_V_BAT_CELL_VDEVMAX, SM_STALE_HIGH, Volts);
  ms_v_bat_cell_valert = new OvmsMetricVector<short>(MS_V_BAT_CELL_VALERT, SM_STALE_HIGH, Other);
  
  ms_v_bat_cell_temp = new OvmsMetricVector<float>(MS_V_BAT_CELL_TEMP, SM_STALE_HIGH, Celcius);
  ms_v_bat_cell_tmin = new OvmsMetricVector<float>(MS_V_BAT_CELL_TMIN, SM_STALE_HIGH, Celcius);
  ms_v_bat_cell_tmax = new OvmsMetricVector<float>(MS_V_BAT_CELL_TMAX, SM_STALE_HIGH, Celcius);
  ms_v_bat_cell_tdevmax = new OvmsMetricVector<float>(MS_V_BAT_CELL_TDEVMAX, SM_STALE_HIGH, Celcius);
  ms_v_bat_cell_talert = new OvmsMetricVector<short>(MS_V_BAT_CELL_TALERT, SM_STALE_HIGH, Other);

  ms_v_charge_voltage = new OvmsMetricFloat(MS_V_CHARGE_VOLTAGE, SM_STALE_MID, Volts);
  ms_v_charge_current = new OvmsMetricFloat(MS_V_CHARGE_CURRENT, SM_STALE_MID, Amps);
  ms_v_charge_climit = new OvmsMetricFloat(MS_V_CHARGE_CLIMIT, SM_STALE_MID, Amps);
  ms_v_charge_time = new OvmsMetricInt(MS_V_CHARGE_TIME, SM_STALE_MID, Seconds);
  ms_v_charge_kwh = new OvmsMetricFloat(MS_V_CHARGE_KWH, SM_STALE_MID, kWh);
  ms_v_charge_mode = new OvmsMetricString(MS_V_CHARGE_MODE, SM_STALE_MID);
  ms_v_charge_timermode = new OvmsMetricBool(MS_V_CHARGE_TIMERMODE, SM_STALE_MID);
  ms_v_charge_timerstart = new OvmsMetricInt(MS_V_CHARGE_TIMERSTART, SM_STALE_MID);
  ms_v_charge_state = new OvmsMetricString(MS_V_CHARGE_STATE, SM_STALE_MID);
  ms_v_charge_substate = new OvmsMetricString(MS_V_CHARGE_SUBSTATE, SM_STALE_MID);
  ms_v_charge_type = new OvmsMetricString(MS_V_CHARGE_TYPE, SM_STALE_MID);
  ms_v_charge_pilot = new OvmsMetricBool(MS_V_CHARGE_PILOT, SM_STALE_MID);
  ms_v_charge_inprogress = new OvmsMetricBool(MS_V_CHARGE_INPROGRESS, SM_STALE_MID);
  ms_v_charge_limit_range = new OvmsMetricFloat(MS_V_CHARGE_LIMIT_RANGE, SM_STALE_HIGH, Kilometers);
  ms_v_charge_limit_soc = new OvmsMetricFloat(MS_V_CHARGE_LIMIT_SOC, SM_STALE_HIGH, Percentage);
  ms_v_charge_duration_full = new OvmsMetricInt(MS_V_CHARGE_DURATION_FULL, SM_STALE_MID, Minutes);
  ms_v_charge_duration_range = new OvmsMetricInt(MS_V_CHARGE_DURATION_RANGE, SM_STALE_MID, Minutes);
  ms_v_charge_duration_soc = new OvmsMetricInt(MS_V_CHARGE_DURATION_SOC, SM_STALE_MID, Minutes);

  ms_v_inv_temp = new OvmsMetricFloat(MS_V_INV_TEMP, SM_STALE_MID, Celcius);
  ms_v_bat_temp = new OvmsMetricFloat(MS_V_BAT_TEMP, SM_STALE_MID, Celcius);
  ms_v_mot_rpm = new OvmsMetricInt(MS_V_MOT_RPM, SM_STALE_MID);
  ms_v_mot_temp = new OvmsMetricFloat(MS_V_MOT_TEMP, SM_STALE_MID, Celcius);
  ms_v_charge_temp = new OvmsMetricFloat(MS_V_CHARGE_TEMP, SM_STALE_MID, Celcius);
  ms_v_env_temp = new OvmsMetricFloat(MS_V_ENV_TEMP, SM_STALE_MID, Celcius);
  ms_v_env_cabintemp = new OvmsMetricFloat(MS_V_ENV_CABINTEMP, SM_STALE_MID, Celcius);

  ms_v_door_fl = new OvmsMetricBool(MS_V_DOOR_FL, SM_STALE_MID);
  ms_v_door_fr = new OvmsMetricBool(MS_V_DOOR_FR, SM_STALE_MID);
  ms_v_door_rl = new OvmsMetricBool(MS_V_DOOR_RL, SM_STALE_MID);
  ms_v_door_rr = new OvmsMetricBool(MS_V_DOOR_RR, SM_STALE_MID);
  ms_v_door_chargeport = new OvmsMetricBool(MS_V_DOOR_CHARGEPORT, SM_STALE_MID);
  ms_v_door_hood = new OvmsMetricBool(MS_V_DOOR_HOOD, SM_STALE_MID);
  ms_v_door_trunk = new OvmsMetricBool(MS_V_DOOR_TRUNK, SM_STALE_MID);

  ms_v_env_drivemode = new OvmsMetricInt(MS_V_ENV_DRIVEMODE, SM_STALE_MID);
  ms_v_env_gear = new OvmsMetricInt(MS_V_ENV_GEAR, SM_STALE_MID);
  ms_v_env_throttle = new OvmsMetricFloat(MS_V_ENV_THROTTLE, SM_STALE_MID, Percentage);
  ms_v_env_footbrake = new OvmsMetricFloat(MS_V_ENV_FOOTBRAKE, SM_STALE_MID, Percentage);
  ms_v_env_handbrake = new OvmsMetricBool(MS_V_ENV_HANDBRAKE, SM_STALE_MID);
  ms_v_env_regenbrake = new OvmsMetricBool(MS_V_ENV_REGENBRAKE, SM_STALE_MID);
  ms_v_env_awake = new OvmsMetricBool(MS_V_ENV_AWAKE, SM_STALE_MID);
  ms_v_env_charging12v = new OvmsMetricBool(MS_V_ENV_CHARGING12V, SM_STALE_MID);
  ms_v_env_cooling = new OvmsMetricBool(MS_V_ENV_COOLING, SM_STALE_MID);
  ms_v_env_heating = new OvmsMetricBool(MS_V_ENV_HEATING, SM_STALE_MID);
  ms_v_env_hvac = new OvmsMetricBool(MS_V_ENV_HVAC, SM_STALE_MID);
  ms_v_env_on = new OvmsMetricBool(MS_V_ENV_ON, SM_STALE_MID);
  ms_v_env_locked = new OvmsMetricBool(MS_V_ENV_LOCKED, SM_STALE_MID);
  ms_v_env_valet = new OvmsMetricBool(MS_V_ENV_VALET, SM_STALE_MID);
  ms_v_env_headlights = new OvmsMetricBool(MS_V_ENV_HEADLIGHTS, SM_STALE_MID);
  ms_v_env_alarm = new OvmsMetricBool(MS_V_ENV_ALARM, SM_STALE_MID);
  ms_v_env_parktime = new OvmsMetricInt(MS_V_ENV_PARKTIME, SM_STALE_MID, Seconds);
  ms_v_env_drivetime = new OvmsMetricInt(MS_V_ENV_DRIVETIME, SM_STALE_MID, Seconds);
  ms_v_env_ctrl_login = new OvmsMetricBool(MS_V_ENV_CTRL_LOGIN, SM_STALE_MID);
  ms_v_env_ctrl_config = new OvmsMetricBool(MS_V_ENV_CTRL_CONFIG, SM_STALE_MID);

  ms_v_pos_gpslock = new OvmsMetricBool(MS_V_POS_GPSLOCK, SM_STALE_MID);
  ms_v_pos_gpsmode = new OvmsMetricString(MS_V_POS_GPSMODE, SM_STALE_MID);
  ms_v_pos_gpshdop = new OvmsMetricFloat(MS_V_POS_GPSHDOP, SM_STALE_MID);
  ms_v_pos_satcount= new OvmsMetricInt(MS_V_POS_SATCOUNT, SM_STALE_MID);
  ms_v_pos_latitude = new OvmsMetricFloat(MS_V_POS_LATITUDE, SM_STALE_MID);
  ms_v_pos_longitude = new OvmsMetricFloat(MS_V_POS_LONGITUDE, SM_STALE_MID);
  ms_v_pos_direction = new OvmsMetricFloat(MS_V_POS_DIRECTION, SM_STALE_MID, Degrees);
  ms_v_pos_altitude = new OvmsMetricFloat(MS_V_POS_ALTITUDE, SM_STALE_MID, Meters);
  ms_v_pos_speed = new OvmsMetricFloat(MS_V_POS_SPEED, SM_STALE_MID, Kph);
  ms_v_pos_acceleration = new OvmsMetricFloat(MS_V_POS_ACCELERATION, SM_STALE_MID, MetersPSS);
  ms_v_pos_gpsspeed = new OvmsMetricFloat(MS_V_POS_GPSSPEED, SM_STALE_MID, Kph);
  ms_v_pos_odometer = new OvmsMetricFloat(MS_V_POS_ODOMETER, SM_STALE_MID, Kilometers);
  ms_v_pos_trip = new OvmsMetricFloat(MS_V_POS_TRIP, SM_STALE_MID, Kilometers);

  ms_v_tpms_fl_t = new OvmsMetricFloat(MS_V_TPMS_FL_T, SM_STALE_MID, Celcius);
  ms_v_tpms_fr_t = new OvmsMetricFloat(MS_V_TPMS_FR_T, SM_STALE_MID, Celcius);
  ms_v_tpms_rr_t = new OvmsMetricFloat(MS_V_TPMS_RR_T, SM_STALE_MID, Celcius);
  ms_v_tpms_rl_t = new OvmsMetricFloat(MS_V_TPMS_RL_T, SM_STALE_MID, Celcius);
  ms_v_tpms_fl_p = new OvmsMetricFloat(MS_V_TPMS_FL_P, SM_STALE_MID, kPa);
  ms_v_tpms_fr_p = new OvmsMetricFloat(MS_V_TPMS_FR_P, SM_STALE_MID, kPa);
  ms_v_tpms_rr_p = new OvmsMetricFloat(MS_V_TPMS_RR_P, SM_STALE_MID, kPa);
  ms_v_tpms_rl_p = new OvmsMetricFloat(MS_V_TPMS_RL_P, SM_STALE_MID, kPa);
  }

MetricsStandard::~MetricsStandard()
  {
  }
